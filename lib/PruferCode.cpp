#include "Solver.h"

std::string Solver::PruferCode(std::vector<std::pair<std::pair<std::string, std::string>, size_t>>& spanning_tree) {
    std::map<std::string, std::set<std::string>> adjacency;

    for (auto [connected, cost] : spanning_tree) {
        adjacency[connected.first].insert(connected.second);
        adjacency[connected.second].insert(connected.first);
    }

    std::string prufer_code;

    // Генерирует коды Прюфера по остову
    while (adjacency.size() > 2) {
        for (auto [leaf, parent] : adjacency) {
            // Убираем лист из списка смежности и добавляем родителя в код.
            if (adjacency[leaf].size() == 1) {
                std::string adjacency_country = *parent.begin();

                adjacency.erase(leaf);
                adjacency[adjacency_country].erase(leaf);
                prufer_code += adjacency_country + ' ';
                break;
            }
        }
    }


    return prufer_code;
}