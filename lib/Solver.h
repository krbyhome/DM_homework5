#include "SetOperations.h"

#include <algorithm>
#include <iostream>
#include <queue>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

//class Solver for tasks of hw

class Solver {
public:
    std::unordered_map<std::string, std::vector<std::string>> graph;
    std::unordered_map<std::string, size_t> index_of;

    void addEdge(const std::string& lhs, const std::string& rhs);

    std::set<std::string> BronKerbosch();

    void BronKerbosch(std::set<std::string> current, std::set<std::string> P, 
                      std::set<std::string> visited,
                      std::set<std::string>& max_clique);

    size_t FindEccentricity(const std::string& country);

    std::pair<std::string, size_t> FindRadius();

    std::pair<std::string, size_t> FindDiameter();

    std::vector<std::string> FindCenter();

    void FindMaximumStableSet(std::set<std::string> stable_set,
                              std::set<std::string> candidates,
                              std::set<std::string>& max_stable_set);

    std::set<std::string> FindMaximumStableSet();

    void FindMaximumMatching(std::vector<std::pair<std::string,std::string>> current,
                             std::set<std::string> candidates,
                             std::vector<std::pair<std::string,std::string>>& max_matcing);

    std::vector<std::pair<std::string,std::string>> FindMaximumMatching();

    std::set<std::string> FindMinimumVertexCover();

    void FindMinimumVertexCover(std::set<std::string> current_vertex_cover,
                                std::set<std::string> candidates,
                                std::set<std::string>& minimum_vertex_cover);

    void FindEulerPath();

    void FindEulerianPath(std::set<std::pair<std::string, std::string>>& used, std::vector<std::string>& path, std::string current);

    void FindMinimumSpanningTree(std::map<std::pair<std::string, std::string>, size_t>& dist,
                                 std::vector<std::pair<std::pair<std::string, std::string>, size_t>>& spanning_tree, std::string start_country);

    std::vector<std::pair<std::pair<std::string, std::string>, size_t>>
    FindMinimumSpanningTree(std::map<std::string, std::vector<std::pair<std::string, int>>> distances);

    void FindCentroid(const std::string& node,
                      std::set<std::string>& used,
                      const std::map<std::pair<std::string, std::string>, size_t>& dist,
                      size_t& weight,
                      std::string prev = "");

    std::pair<std::string, size_t> FindCentroid(std::vector<std::pair<std::pair<std::string, std::string>, size_t>>& T);

    std::string PruferCode(std::vector<std::pair<std::pair<std::string, std::string>, size_t>>& spanning_tree);
};

void print(std::vector<int> container);

std::istream& operator>>(std::istream&, Solver& g);