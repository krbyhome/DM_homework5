#include "Solver.h"

//find the eccentricity for each vertex and update the diameter

std::pair<std::string, size_t> Solver::FindDiameter() {
    std::pair<std::string, size_t> diameter = {"", 0};

    for (auto [from, to]: graph) {
        size_t eccentricity = FindEccentricity(from);
        if (eccentricity > diameter.second) {
            diameter.first = from;
            diameter.second = eccentricity;
        }
    }

    return diameter;
}