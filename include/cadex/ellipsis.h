#ifndef CADEX_ELLIPSIS_H
#define CADEX_ELLIPSIS_H

#include "curves.h"
#include "parametric.h"

namespace curves {

    class Ellipses : public DifferentiableParametricFunction {
    public:
        Ellipses(double xRadii, double yRadii);

        double getXRadius() const;

        double getYRadius() const;

        void setXRadius(double xRadius);

        void setYRadius(double yRadius);

        Point value(double t) const override;

        Point derivativeValue(double t) const override;

    private:
        double xRadius;
        double yRadius;
    };

}
#endif //CADEX_ELLIPSIS_H