#include "World.hpp"
#include "Painter.hpp"
#include "Ball.hpp"
#include <fstream>

// Длительность одного тика симуляции.
// Подробнее см. update()
// Изменять не следует
static constexpr double timePerTick = 0.001;

/**
 * Конструирует объект мира для симуляции
 * @param worldFilePath путь к файлу модели мира
 */
World::World(const std::string& worldFilePath) {

    std::ifstream stream(worldFilePath);
    
    // Читаем границы мира
    stream >> topLeft.x >> topLeft.y >> bottomRight.x >> bottomRight.y;
    physics.setWorldBox(topLeft, bottomRight);

    // Переменные для чтения данных о шарах
    double x;
    double y;
    double vx;
    double vy;
    double radius;
    double red;
    double green;
    double blue;
    bool isCollidable;

    // Читаем шары из файла
    while (stream.peek(), stream.good()) {
        // Читаем координаты центра шара (x, y) и вектор его скорости (vx, vy)
        stream >> x >> y >> vx >> vy;
        // Читаем три составляющие цвета шара
        stream >> red >> green >> blue;
        // Читаем радиус шара
        stream >> radius;
        // Читаем свойство шара isCollidable
        stream >> std::boolalpha >> isCollidable;

        // Создаём шар и добавляем его в вектор
        Point center(x, y);
        Velocity velocity(vx, vy);
        Ball ball(center, velocity, radius, red, green, blue, isCollidable);
        balls.push_back(ball);
    }
}

/// @brief Отображает состояние мира
void World::show(Painter& painter) const {
    // Рисуем белый прямоугольник, отображающий границу мира
    painter.draw(topLeft, bottomRight, Color(1, 1, 1));

    // Вызываем отрисовку каждого шара
    for (const Ball& ball : balls) {
        ball.draw(painter);
    }
}

/// @brief Обновляет состояние мира
void World::update(double time) {
    // учитываем остаток времени, который мы не "доработали" при прошлом update
    time += restTime;
    const auto ticks = static_cast<size_t>(std::floor(time / timePerTick));
    restTime = time - double(ticks) * timePerTick;

    physics.update(balls, ticks);
}