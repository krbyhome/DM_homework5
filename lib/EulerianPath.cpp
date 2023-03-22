#include "Solver.h"

// Находит эйлеров путь и выводит его

void Solver::FindEulerianPath(std::set<std::pair<std::string, std::string>>& used, std::vector<std::string>& path, std::string current) {
    for (const auto& to : graph[current]) {
        if (!used.count({current, to})) {
            used.insert({current, to});
            used.insert({to, current});
            FindEulerianPath(used, path, to);
        }
    }

    /* Adding the current node to the path. */
    path.emplace_back(current);
};

void Solver::FindEulerPath() {
    std::vector<std::string> path;
    std::set<std::pair<std::string, std::string>> used;

    FindEulerianPath(used, path, "Country");

    reverse(path.begin(), path.end());

    for (const auto& country : path) {
        std::cout << country << " - ";
    }
}