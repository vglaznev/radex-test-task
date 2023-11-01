#include "random-number.h"
#include <random>

double randomDouble(double lowLimit, double highLimit) {
    static std::random_device r;
    static std::default_random_engine engine(r());
    using Distribution = std::uniform_real_distribution<double>;
    static Distribution distribution;
    return distribution(engine, Distribution::param_type {lowLimit, highLimit});
}

int randomInt(int lowLimit, int highLimit) {
    static std::random_device r;
    static std::default_random_engine engine(r());
    using Distribution = std::uniform_int_distribution<int>;
    static Distribution distribution;
    return distribution(engine, Distribution::param_type {lowLimit, highLimit});
}
