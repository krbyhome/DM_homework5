#include "graph.h"

/// Task (n) Add the weight functionw : E → R denoting the distance between capitals. Find the minimum
//(w.r.t. the total weight of edges) spanning tree T for the largest connected component of the
//weighted Europe graph G

int main() {
    Solver g;
    europe >> g;
    std::vector<std::pair<std::pair<std::string, std::string>, size_t>> minimum_spanning_tree = g.FindMinimumSpanningTree(distances);

    size_t length_of_spanning_tree = 0;

    for (auto dist : minimum_spanning_tree) {
        length_of_spanning_tree += dist.second;
    }
    std::cout << "Sum of edges in minimum spanning tree : " << length_of_spanning_tree << '\n';

    for (auto [connected, cost] : minimum_spanning_tree) {
        std::cout << connected.first << " " << connected.second << " " << cost << '\n';
    }

    return 0;
}