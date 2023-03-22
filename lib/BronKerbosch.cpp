#include "Solver.h"

/*
Реализация алгоритма для нахождения максимальной клики в графе
current  - текущая клика
P - множество возможных вершин в макс клике
visited - использованные вершины
max_clique - множество вершин в максимальной клике
*/

void Solver::BronKerbosch(std::set<std::string> current, std::set<std::string> P, std::set<std::string> visited,
                               std::set<std::string>& max_clique) {

// если оба множества P и visited пусты, то текущая клика максимальная
    if (P.empty() && visited.empty()) {
        if (current.size() > max_clique.size()) {
            max_clique = current;
        }
    }

    auto cur = current;

// Для каждой потенциальной вершины рекурсивно вызывает алгоритм с графом индуцированным соседями v
    for (const auto& v : current) {
        BronKerbosch(Union(current, {v}),
                     Intersection(cur, VectorToSet(graph[v])),
                     Intersection(visited, VectorToSet(graph[v])),
                     max_clique);

        cur = Difference(cur, {v});
        visited = Union(visited, {v});
    }
}

//Оболочка к алгоритму

std::set<std::string> Solver::BronKerbosch() {

// Инициализация кандидатов для добавления в клику
    std::set<std::string> candidates;
    for (auto [from, to] : graph) {
        candidates.insert(from);
    }

    std::set<std::string> max_clique;

    BronKerbosch({}, candidates, {}, max_clique);

    return max_clique;
}