#pragma once

#include "Painter.hpp"
#include "Point.hpp"
#include "Velocity.hpp"

class Ball {
public:
    // Конструктор (нужно добавить!)
    Ball(const Point& center, const Velocity& velocity, double radius, double red, double green, double blue, bool collidable);
    
    void setVelocity(const Velocity& velocity);
    Velocity getVelocity() const;
    void setCenter(const Point& center);
    Point getCenter() const;
    double getRadius() const;
    double getMass() const;
    void draw(Painter& painter) const;
    
private:
    Point center_;      // центр шара
    Velocity velocity_; // скорость шара
    double radius_;     // радиус
    double red_;        // компонента красного цвета (0-1)
    double green_;      // компонента зелёного цвета (0-1)
    double blue_;       // компонента синего цвета (0-1)
    bool collidable_;   // можно ли с ним сталкиваться
};
