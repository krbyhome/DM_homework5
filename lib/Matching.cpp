#include "Solver.h"

/**
 * Берет множество кандидатов и для каждого проверяет есть ли в другом множестве потенциальная вершина соединенная с ней. 
 * Если да, то добавляет вершину в матчинг и рекурсивно вызывает себя с новым списком потенциальных вершин
 */
void Solver::FindMaximumMatching(std::vector<std::pair<std::string,std::string>> current,
                                      std::set<std::string> candidates,
                                      std::vector<std::pair<std::string,std::string>>& max_matching) {

    bool flag = false;

    auto tmp_candidates = candidates;

    // нахождение максимального матчинга
    for (const auto& country : tmp_candidates) {
        for (const auto& to_country : graph[country]) {
            if (candidates.count(to_country)) {
                if (!flag) current.emplace_back();
                flag = true;
                current.back() = {country, to_country};
                FindMaximumMatching(current,
                                    Difference(candidates, {country, to_country}),
                                    max_matching);
            }
        }

        candidates.erase(country);
    }

    //Проверка на максимум
    if (current.size() > max_matching.size() && !flag) {

        std::cout << "Founded matching " << current.size() << '\n';

        for (auto [from, to] : current) {
            std::cout << from << " " << to << '\n';
        }

        max_matching = current;
    }
}

//оболочка

std::vector<std::pair<std::string,std::string>> Solver::FindMaximumMatching() {
    std::set<std::string> candidates;

    for (auto [from, to] : graph) {
        candidates.insert(from);
    }

    std::vector<std::pair<std::string,std::string>> max_matching;

    FindMaximumMatching({}, candidates, max_matching);

    return max_matching;
}