#include "SetOperations.h"

//taking two sets as arguments and returns their union.

std::set<std::string> Union(const std::set<std::string>& lhs, const std::set<std::string>& rhs) {
    std::set<std::string> tmp = lhs;

    for (const std::string& x : rhs) {
        tmp.insert(x);
    }

    return tmp;
}

//Taking two sets and returning their intersection.

std::set<std::string> Intersection(const std::set<std::string>& lhs, const std::set<std::string>& rhs) {
    std::set<std::string> tmp;

    for (const std::string& x : lhs) {
        if (rhs.count(x)) tmp.insert(x);
    }

    return tmp;
}

//Taking two sets and returning their difference.

std::set<std::string> Difference(const std::set<std::string>& lhs, const std::set<std::string>& rhs) {
    std::set<std::string> tmp = lhs;

    for (const std::string& x : rhs) {
        tmp.erase(x);
    }

    return tmp;
};

//Converting a vector to a set.

std::set<std::string> VectorToSet(const std::vector<std::string>& vec) {
    std::set<std::string> tmp;

    for (const std::string& x : vec) {
        tmp.insert(x);
    }

    return tmp;
}