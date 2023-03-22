#include "Solver.h"

//It finds the maximum distance from a given country

size_t Solver::FindEccentricity(const std::string& country) {
    std::unordered_map<std::string, size_t> dist;
    std::queue<std::string> q;

    q.push(country);
    dist[country] = 0;

    size_t eccentricity = 0;

    //bfs 
    while (!q.empty()) {
        auto from_county = q.front();
        q.pop();

        for (const auto& to_country : graph[from_county]) {
            if (!dist.count(to_country) || dist[to_country] > dist[from_county] + 1) {
                dist[to_country] = dist[from_county] + 1;
                eccentricity = std::max(eccentricity, dist[to_country]);
                q.push(to_country);
            }
        }
    }

    return eccentricity;
}