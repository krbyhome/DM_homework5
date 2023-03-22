#include "graph.h"

// Task (k) Find the closed walk U that visits every edges

int main() {
    Solver g;
    europe >> g;

    Solver reduced;
    reduced_europe >> reduced;

    reduced.FindEulerPath();

    return 0;
}