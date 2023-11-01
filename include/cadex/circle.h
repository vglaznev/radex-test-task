#ifndef CADEX_CIRCLE_H
#define CADEX_CIRCLE_H

#include "curves.h"
#include "parametric.h"

namespace curves {

    class Circle : public DifferentiableParametricFunction {
    public:
        explicit Circle(double radius);

        double getRadius() const;

        void setRadius(double radius);

        Point value(double t) const override;

        Point derivativeValue(double t) const override;

    private:
        double radius;
    };

}
#endif //CADEX_CIRCLE_H
