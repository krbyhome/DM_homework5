#include "graph.h"

//Task (e) Find maximum clique



int main() {
    Solver g;
    europe >> g;
    auto max_clique = g.BronKerbosch();

    std::cout << "Max clique: ";
    for (auto x : max_clique) std::cout << x << " ";

    g.BronKerbosch();

    for (auto [from, edges] : g.matching_vertex_to_edges) {
        std :: cout << "From : " << from << '\n';
       for (auto x : edges) {
            for (auto y : x) {
                std :: cout << y << " ";
            }
            std::cout << '\n';
        }
    }

    return 0;
}