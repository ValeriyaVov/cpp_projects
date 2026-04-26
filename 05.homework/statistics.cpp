#include <iostream>
#include <limits>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>

class IStatistics {
public:
	virtual ~IStatistics() {}

	virtual void update(double next) = 0;
	virtual double eval() const = 0;
	virtual const char * name() const = 0;
};

class Min : public IStatistics {
public:
	Min() : m_min{std::numeric_limits<double>::max()} {
	}

	void update(double next) override {
		if (next < m_min) {
			m_min = next;
		}
	}

	double eval() const override {
		return m_min;
	}

	const char * name() const override {
		return "min";
	}

private:
	double m_min;
};


class Max : public IStatistics {
public:
    Max() : m_max{std::numeric_limits<double>::lowest()} {}

    void update(double next) override {
        if (next > m_max) {
            m_max = next;
        }
    }

    double eval() const override {
        return m_max;
    }

    const char * name() const override {
        return "max";
    }

private:
    double m_max;
};


class Mean : public IStatistics {
public:
    Mean() : m_sum{0.0}, m_count{0} {}

    void update(double next) override {
        m_sum += next;
        ++m_count;
    }

    double eval() const override {
        if (m_count == 0) return 0.0;
        return m_sum / m_count;
    }

    const char * name() const override {
        return "mean";
    }

private:
    double m_sum;
    size_t m_count;
};


// Стандартное отклонение (Std)
class Std : public IStatistics {
public:
    void update(double next) override {
        m_values.push_back(next);
    }

    double eval() const override {
        if (m_values.empty()) return 0.0;

        double sum = 0.0;
        for (double v : m_values) sum += v;
        double mean = sum / m_values.size();

        double sq_sum = 0.0;
        for (double v : m_values) {
            double diff = v - mean;
            sq_sum += diff * diff;
        }

        return std::sqrt(sq_sum / m_values.size());
    }

    const char* name() const override { return "std"; }

private:
    std::vector<double> m_values;
};

int main() {
    const size_t stats_count = 4;
    IStatistics* stats[stats_count];

    stats[0] = new Min();
    stats[1] = new Max();
    stats[2] = new Mean();
    stats[3] = new Std();

    double value;
    while (std::cin >> value) {
        for (size_t i = 0; i < stats_count; ++i) {
            stats[i]->update(value);
        }
    }

    for (size_t i = 0; i < stats_count; ++i) {
        std::cout << stats[i]->name() << " = " << stats[i]->eval() << std::endl;
    }

    for (size_t i = 0; i < stats_count; ++i) {
        delete stats[i];
    }

    return 0;
}