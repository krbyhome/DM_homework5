#include "Solver.h"

/*
 Для каждой вершины считает эксцентриситет и если он равен радиусу , то добавляет вершину в вектор центров
 */

std::vector<std::string> Solver::FindCenter() {
    size_t radius = FindRadius().second;
    std::vector<std::string> center;

    for (const auto& [from, to] : graph) {
        if (FindEccentricity(from) == radius) {
            center.emplace_back(from);
        }
    }

    return center;
}