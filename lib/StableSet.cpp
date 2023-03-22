#include "Solver.h"

//Для каждой страны в списке кандидатов, убираем ее оттуда и добавляем в stable set

void Solver::FindMaximumStableSet(std::set<std::string> stable_set,
                                       std::set<std::string> candidates,
                                       std::set<std::string>& max_stable_set){
    if (candidates.empty()) {

        if (stable_set.size() > max_stable_set.size()) {
            max_stable_set = stable_set;
        }
    }

    std::set<std::string> tmp_candidates = candidates;

    for (const auto& country : tmp_candidates) {
        candidates.erase(country);
        //Добавляет страну в stable set и убирает вершины соединенные с теми что в списке кандидатов
        FindMaximumStableSet(Union(stable_set, {country}),
                             Difference(candidates, VectorToSet(graph[country])),
                             max_stable_set);
    }

}

std::set<std::string> Solver::FindMaximumStableSet() {
    std::set<std::string> candidates;

    for (auto [from, to] : graph) {
        candidates.insert(from);
    }

    std::set<std::string> max_stable_set;

    FindMaximumStableSet({}, candidates, max_stable_set);

    return max_stable_set;
}