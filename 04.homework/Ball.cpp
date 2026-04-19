#include "Ball.hpp"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Конструктор
Ball::Ball(const Point& center, const Velocity& velocity, double radius, 
           double red, double green, double blue, bool collidable)
    : center_(center)
    , velocity_(velocity)
    , radius_(radius)
    , red_(red)
    , green_(green)
    , blue_(blue)
    , collidable_(collidable) {
}

void Ball::setVelocity(const Velocity& velocity) {
    velocity_ = velocity;
}

Velocity Ball::getVelocity() const {
    return velocity_;
}

void Ball::draw(Painter& painter) const {
    // Рисуем шар цветом из файла
    Color color(red_, green_, blue_);
    painter.draw(center_, radius_, color);
}

void Ball::setCenter(const Point& center) {
    center_ = center;
}

Point Ball::getCenter() const {
    return center_;
}

double Ball::getRadius() const {
    return radius_;
}

double Ball::getMass() const {
    // Масса = плотность * объём
    // Плотность = 1 (условно), объём шара = 4/3 * PI * r^3
    return (4.0 / 3.0) * M_PI * radius_ * radius_ * radius_;
}