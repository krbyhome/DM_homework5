#include "graph.h"

//Task (f) Find maximum stable set

int main() {
    Solver g;
    europe >> g;

    auto maximum_stable_set = g.FindMaximumStableSet();
    std::cout << "\nmaximum stable set : \n";
    for (const auto& x : maximum_stable_set) {
        std::cout << x << " ";
    }

    return 0;
}