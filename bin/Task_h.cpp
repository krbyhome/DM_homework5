#include "graph.h"

// Task (h) Find minimum vertex cover

int main() {
    Solver g;
    europe >> g;

    auto minimum_vertex_cover = g.FindMinimumVertexCover();

    std::cout << "Minimum vertex cover : \n";
    for (auto x : minimum_vertex_cover) {
        std::cout << x << ' ';
    }
    return 0;
}