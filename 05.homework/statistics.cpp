#include <iostream>
#include <limits>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>

class IStatistics {
public:
    IStatistics(const char* name) : m_name(name), m_value(0.0) {}
    virtual ~IStatistics() = default;
    
    virtual void update(double next) = 0;
    virtual double eval() const = 0;
    
    const char* name() const { return m_name; }

protected:
    double m_value;

private:
    const char* m_name;
};

class Min : public IStatistics {
public:
    Min() : IStatistics("Min") {
        m_value = std::numeric_limits<double>::max();
    }

    void update(double next) override {
        if (next < m_value) {
            m_value = next;
        }
    }

    double eval() const override {
        if (m_value == std::numeric_limits<double>::max()) {
            throw std::logic_error("No values provided");
        }
        return m_value;
    }
};

class Max : public IStatistics {
public:
    Max() : IStatistics("Max") {
        m_value = std::numeric_limits<double>::lowest();
    }

    void update(double next) override {
        if (next > m_value) {
            m_value = next;
        }
    }

    double eval() const override {
        if (m_value == std::numeric_limits<double>::lowest()) {
            throw std::logic_error("No values provided");
        }
        return m_value;
    }
};

class Mean : public IStatistics {
public:
    Mean() : IStatistics("Mean"), m_value(0.0), m_count(0) {}

    void update(double next) override {
        m_value += next;
        ++m_count;
    }

    double eval() const override {
        if (m_count == 0) {
            throw std::logic_error("No values provided");
        }
        return m_value / m_count;
    }

private:
    double m_value; 
    size_t m_count;
};

class StandardDeviation : public IStatistics {
public:
    StandardDeviation() : IStatistics("Standard Deviation") {}

    void update(double next) override {
        m_values.push_back(next);
    }

    double eval() const override {
        if (m_values.empty()) {
            throw std::logic_error("No values provided");
        }

        double sum = 0.0;
        for (double v : m_values) {
            sum += v;
        }
        double mean = sum / m_values.size();

        double sq_sum = 0.0;
        for (double v : m_values) {
            double diff = v - mean;
            sq_sum += diff * diff;
        }

        return std::sqrt(sq_sum / m_values.size());
    }

private:
    std::vector<double> m_values;
};

int main() {
    const size_t stats_count = 4;
    IStatistics* stats[stats_count];

    stats[0] = new Min();
    stats[1] = new Max();
    stats[2] = new Mean();
    stats[3] = new StandardDeviation();

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