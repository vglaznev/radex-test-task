#ifndef CADEX_PARAMETRIC_H
#define CADEX_PARAMETRIC_H

namespace curves {

    struct Point {
        double x;
        double y;
        double z;
    };

    class ParametricFunction {
    public:
        virtual Point getPointAt(double t) const = 0;

        virtual ~ParametricFunction() = default;
    };

    class DifferentiableParametricFunction : public ParametricFunction {
    public:
        virtual Point getDerivativeAt(double t) const = 0;
    };

}
#endif //CADEX_PARAMETRIC_H
