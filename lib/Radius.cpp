#include "Solver.h"

//Find the Eccentricity for each vertex and update radius

std::pair<std::string, size_t> Solver::FindRadius() {
    std::pair<std::string, size_t> radius = {"", INT_MAX};

    for (auto [from, to]: graph) {
        size_t eccentricity = FindEccentricity(from);
        if (eccentricity < radius.second) {
            radius.first = from;
            radius.second = eccentricity;
        }
    }

    return radius;
}