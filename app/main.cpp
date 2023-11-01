#define FMT_HEADER_ONLY

#include "fmt/format.h"

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <numeric>

#include "cadex/curves.h"
#include "random-number.h"

template<>
struct fmt::formatter<curves::Point> {
    template<typename ParseContext>
    constexpr auto parse(ParseContext &ctx) {
        return ctx.begin();
    }

    template<typename FormatContext>
    auto format(const curves::Point &point, FormatContext &ctx) {
        return fmt::format_to(ctx.out(), "({:.3f}, {:.3f}, {:.3f})", point.x, point.y, point.z);
    };
};

std::vector<std::unique_ptr<curves::DifferentiableParametricFunction>> createContainerOfRandomCurves() {
    enum class CurveType {
        Circle = 0,
        Ellipsis = 1,
        Helix = 2
    };

    int numberOfCurves = randomInt(5, 15);
    std::vector<std::unique_ptr<curves::DifferentiableParametricFunction>> curves;
    for (int i = 0; i < numberOfCurves; i++) {
        auto type = static_cast<CurveType>(randomInt(0, 2));
        double firstRandomParameter = randomDouble(0.5, 4.5);
        double secondRandomParameter = randomDouble(0.5, 4.5);
        switch (type) {
            case CurveType::Circle:
                curves.push_back(std::make_unique<curves::Circle>(firstRandomParameter));
                fmt::println("{:2} | Circle   | Radius   = {:.3f} |{: <18}|", i, firstRandomParameter, "");
                break;
            case CurveType::Ellipsis:
                curves.push_back(std::make_unique<curves::Ellipses>(firstRandomParameter, secondRandomParameter));
                fmt::println("{:2} | Ellipses | X radius = {:.3f} | Y radius = {:.3f} |", i, firstRandomParameter,
                             secondRandomParameter);
                break;
            case CurveType::Helix:
                curves.push_back(std::make_unique<curves::Helix>(firstRandomParameter, secondRandomParameter));
                fmt::println("{:2} | Helix    | Radius   = {:.3f} | Step     = {:.3f} |", i, firstRandomParameter,
                             secondRandomParameter);
                break;
        }
    }
    return curves;
}

void printCircles(const std::vector<const curves::Circle *> &circles) {
    for (int i = 0; i < circles.size(); i++) {
        fmt::println("{:2} | Circle  | Radius = {:.3f} |", i, circles.at(i)->getRadius());
    }
}

int main() {

    //2. Populate a container (e.g. vector or list) of objects of these types created in random manner with
    //random parameters.
    fmt::print("Generated curves:\n");
    auto curves = createContainerOfRandomCurves();
    fmt::print("\n");

    //3. Print coordinates of points and derivatives of all curves in the container at t=PI/4.
    fmt::println("Coordinates of points and derivatives at PI/4:");
    fmt::println("   |{: ^23}|{: ^23}", "Point", "Derivative");
    double parameter = M_PI / 4;
    for (int i = 0; i < curves.size(); i++) {
        fmt::println("{0:2} | {1} | {2} |", i, curves.at(i)->value(parameter),
                     curves.at(i)->derivativeValue(parameter));
    }
    //4. Populate a second container that would contain only circles from the first container. Make sure the
    //second container shares (i.e. not clones) circles of the first one, e.g. via pointers.
    std::vector<const curves::Circle *> circles;
    std::for_each(curves.begin(), curves.end(),
                  [&circles](const auto &curveOwnPtr) {
                      const auto curvePtr = curveOwnPtr.get();
                      if (const auto circlePtr = dynamic_cast<const curves::Circle *>(curvePtr))
                          circles.push_back(circlePtr);
                  });

    fmt::println("\nCircles:");
    printCircles(circles);

    //5. Sort the second container in the ascending order of circles’ radii. That is, the first element has the
    //smallest radius, the last - the greatest
    std::sort(circles.begin(), circles.end(), [](const auto a, const auto b) {
        return a->getRadius() < b->getRadius();
    });

    fmt::println("\nCircles after sorting by radii:");
    printCircles(circles);

    //6. Compute the total sum of radii of all curves in the second container.
    //8. Implement computation of the total sum of radii using parallel computations
    double sumOfRadii = 0.0;

#pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < circles.size(); i++) {
        sumOfRadii += circles.at(i)->getRadius();
    }

    fmt::println("\nSum of radii in second container: {:.3f}", sumOfRadii);

    return 0;
}
