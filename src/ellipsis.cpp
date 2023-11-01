#include "cadex/ellipsis.h"

#include <cmath>
#include <stdexcept>

namespace curves {

    Ellipses::Ellipses(double xRadii, double yRadii) : xRadius(xRadii), yRadius(yRadii) {
        if (xRadii <= 0 || yRadii <= 0) {
            throw std::invalid_argument("One of radii is less or equal to zero");
        }
    }

    Point Ellipses::getPointAt(double t) const {
        double x = xRadius * std::cos(t);
        double y = yRadius * std::sin(t);
        return {.x = x, .y = y, .z = 0};
    }

    double Ellipses::getXRadius() const {
        return xRadius;
    }

    double Ellipses::getYRadius() const {
        return yRadius;
    }

    void Ellipses::setXRadius(double xRadius) {
        this->xRadius = xRadius;
    }

    void Ellipses::setYRadius(double yRadius) {
        this->yRadius = yRadius;
    }

    Point Ellipses::getDerivativeAt(double t) const {
        double xDer = -xRadius * std::sin(t);
        double yDer = yRadius * std::cos(t);
        return {.x = xDer, .y = yDer, .z = 0};
    }

}