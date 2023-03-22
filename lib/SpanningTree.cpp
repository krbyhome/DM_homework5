#include "Solver.h"

/**
 * Находит минимальный остов
 *
 * Args:
 *   dist: мапа расстояний между странами
 *   spanning_tree: само дерево в виде пар строк
 *   start_country: страна с которой начинается дерево
 */

void Solver::FindMinimumSpanningTree(std::map<std::pair<std::string, std::string>, size_t>& dist,
                                          std::vector<std::pair<std::pair<std::string, std::string>, size_t>>& spanning_tree, std::string start_country) {
    // Получаем |V|
    size_t V = graph.size();
    size_t used_edge = 0;

    // Переменные для вершин с минимальным расстоянием
    std::string x;
    std::string y;

    // Множество для использованных вершин
    std::set<std::string> used;
    used.insert(start_country);

    // Исполняется пока вершин не станет ровно V - 1 т.к дальше граф перестанет быть деревом
    while (used_edge < V - 1) {
        // чистим переменные
        size_t mn = INT_MAX;
        x.clear();
        y.clear();

        // Перебираем все страны в графе
        for (auto [i_country, i_to] : graph) {
            // Проверка на использованность
            if (used.count(i_country)) {
                // Бежим по соседям
                for (auto j_country : i_to) {
                    // Проверка на минимальную дистанцию до соседа и его использованность
                    if (!used.count(j_country) && mn > dist[{i_country, j_country}]) {
                        mn = dist[{i_country, j_country}];
                        x = i_country;
                        y = j_country;
                    }
                }
            }
        }

        // Добавляем ребро в дерево
        spanning_tree.push_back({{x, y}, dist[{x, y}]});

        // помечаем вершину использованной
        used.insert(y);
        used_edge++;
    }
}

//оболочка к алгоритму

std::vector<std::pair<std::pair<std::string, std::string>, size_t>> Solver::FindMinimumSpanningTree(std::map<std::string, std::vector<std::pair<std::string, int>>> distances) {
    // конвертирует мапу в вид {страна, страна, расстояние}
    std::map<std::pair<std::string, std::string>, size_t> dist;
    for (auto [from, to] : distances) {
        for (auto [country, cost] : to) {
            dist[{from, country}] = cost;
        }
    }

    std::vector<std::pair<std::pair<std::string, std::string>, size_t>> minimum_spanning_tree;
    int minimum_length = INT_MAX;

    // Перебираем все вершины в графе
    for (auto [start_country, to] : graph)  {
        // Находим минимальный остов из этой страны
        std::vector<std::pair<std::pair<std::string, std::string>, size_t>> spanning_tree;
        FindMinimumSpanningTree(dist, spanning_tree, start_country);

        // Считаем длину
        size_t length = 0;
        for (auto [connected, cost] : spanning_tree) {
            length += cost;
        }

        // Обновляем длину если она меньше
        if (length < minimum_length) {
            minimum_length = length;
            minimum_spanning_tree = spanning_tree;
        }
    }

    // Возращаем минимальный остов
    return minimum_spanning_tree;
}

//Находит центроид

void Solver::FindCentroid(const std::string& node,
                               std::set<std::string>& used,
                               const std::map<std::pair<std::string, std::string>, size_t>& dist,
                               size_t& weight, std::string prev) {
    used.insert(node);
    for (const auto& to : graph[node]) {
        // Проверка на то что текущий узел был предыдущим и на нахождение расстояния между вершинами в мапе расстояний
        if (to == prev || !dist.count({node, to})) continue;
        // Нахождение расстояние между узлами
        weight += dist.find({to, node})->second;

        // идем к неиспользованным вершинам
        if (!used.count(to)) {
            FindCentroid(to, used, dist, weight, node);
        }
    }
}

std::pair<std::string, size_t> Solver::FindCentroid(std::vector<std::pair<std::pair<std::string, std::string>, size_t>>& T) {
    size_t min_weight = INT_MAX;
    std::string centroid;

    std::map<std::pair<std::string, std::string>, size_t> dist;

    for (auto [connecting, cost] : T) {
        dist[connecting] =  cost;
        dist[{connecting.second, connecting.first}] = cost;
    }

    for (auto [from, to] : graph) {
        size_t max_weight = 0;

        std::set<std::string> used;
        used.insert(from);

        for (auto branch_start : to) {
            if (!used.count(branch_start) && dist.count({from, branch_start})) {
                size_t weight_of_this_component = dist[{from, branch_start}];
                FindCentroid(branch_start, used, dist, weight_of_this_component, "");

                if (weight_of_this_component > max_weight) max_weight = weight_of_this_component;
            }
        }

        if (max_weight < min_weight) {
            centroid = from;
            min_weight = max_weight;
        }
    }

    return {centroid, min_weight};
}