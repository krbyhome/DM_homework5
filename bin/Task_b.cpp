#include "graph.h"

// Task (b) find radius(g), diameter(g), center(g)

int main() {
    Solver g;
    europe >> g;

    auto [country, radius] = g.FindRadius();
    std::cout << "Country : " << country << " radius : " << radius << '\n';

    auto diameter = g.FindDiameter();
    std::cout << "Country : " << diameter.first << " diameter : " << diameter.second << '\n';

    auto center = g.FindCenter();
    std::cout << "Center : ";

    for (const auto& node : center) {
        std::cout << node << " ";
    }
    std::cout << '\n';

    return 0;
}