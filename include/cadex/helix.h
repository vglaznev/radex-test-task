#ifndef CADEX_HELIX_H
#define CADEX_HELIX_H

#include "curves.h"
#include "parametric.h"

namespace curves {

    class Helix : public DifferentiableParametricFunction {
    public:
        Helix(double radius, double step);

        double getRadius() const;

        double getStep() const;

        void setRadius(double radius);

        void setStep(double step);

        Point value(double t) const override;

        Point derivativeValue(double t) const override;

    private:
        double radius;
        double step;
    };

}
#endif //CADEX_HELIX_H
