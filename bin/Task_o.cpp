#include "graph.h"

//Find centroid in G

int main() {
    Solver g;
    europe >> g;

    auto T = g.FindMinimumSpanningTree(distances);
    auto centroid = g.FindCentroid(T);

    std::cout << "Founded centroid : " << centroid.first << " " << centroid.second << '\n';

    return 0;
}