#include "cadex/circle.h"

#include <cmath>
#include <stdexcept>

namespace curves {
    Circle::Circle(double radius) : radius(radius) {
        if (radius <= 0) {
            throw std::invalid_argument("Radius is less or equal to zero");
        }
    }

    Point Circle::getPointAt(double t) const {
        double x = radius * std::cos(t);
        double y = radius * std::sin(t);
        return {.x = x, .y = y, .z = 0};
    }

    double Circle::getRadius() const {
        return radius;
    }

    void Circle::setRadius(double radius) {
        this->radius = radius;
    }

    Point Circle::getDerivativeAt(double t) const {
        double x = -radius * std::sin(t);
        double y = radius * std::cos(t);
        return {.x = x, .y = y, .z = 0};
    }
}