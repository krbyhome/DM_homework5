#include "graph.h"

//Task(p) Construct the Prufer code of spanning tree

int main() {
    Solver g;
    europe >> g;

    auto T = g.FindMinimumSpanningTree(distances);
    std::string prufer_code = g.PruferCode(T);

    std::cout << "Constructed the Prufer code : " << std::endl;

    std::cout << prufer_code;

    return 0;
}