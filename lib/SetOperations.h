#include <set>
#include <string>
#include <vector>
#include <iostream>

//объединяет два множества
std::set<std::string> Union(const std::set<std::string>& lhs, const std::set<std::string>& rhs);

//пересекает два множества
std::set<std::string> Intersection(const std::set<std::string>& lhs, const std::set<std::string>& rhs);

//вычитает два множества
std::set<std::string> Difference(const std::set<std::string>& lhs, const std::set<std::string>& rhs);

// переводит vector в set
std::set<std::string> VectorToSet(const std::vector<std::string>& vec);