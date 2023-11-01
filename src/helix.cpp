#include "cadex/helix.h"

#include <cmath>
#include <stdexcept>

namespace curves {

    Helix::Helix(double radius, double step) : radius(radius), step(step) {
        if (radius <= 0) {
            throw std::invalid_argument("Radius is less or equal to zero");
        }
    }

    Point Helix::getPointAt(double t) const {
        double x = radius * std::cos(t);
        double y = radius * std::sin(t);
        double z = step * t;
        return {.x = x, .y = y, .z = z};
    }

    double Helix::getRadius() const {
        return radius;
    }

    double Helix::getStep() const {
        return step;
    }

    void Helix::setRadius(double radius) {
        this->radius = radius;
    }

    void Helix::setStep(double step) {
        this->step = step;
    }

    Point Helix::getDerivativeAt(double t) const {
        double xDer = -radius * std::sin(t);
        double yDer = radius * std::cos(t);
        double zDer = step;
        return {.x = xDer, .y = yDer, .z = zDer};
    }

}