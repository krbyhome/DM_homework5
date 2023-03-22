#include "graph.h"

int main() {



/// Task (o) Find centroid(T ) (w.r.t. the edge weight function w).

    auto T = g.FindMinimumSpanningTree(distances);

    auto centroid = g.FindCentroid(T);

    std::cout << "Founded centroid : " << centroid.first << " " << centroid.second << '\n';

/// Task (p) Construct the Prufer code for  ̈ T.

    std::string prufer_code = g.PruferCode(T);

    std::cout << "Constructed the Prufer code : " << std::endl;

    std::cout << prufer_code;
}
