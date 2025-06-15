//
// Created by Damon on 2025/6/15.
//

#include "my_algorithms.h"
#include <set>

pair<int, int> SumToTarget(vector<int> vec, int target)
{
    if (vec.empty()) { return make_pair(-1, -1); }
    set<int> rest;
    for (int i = 0; i < vec.size(); i++) {
        if (rest.find(vec[i]) != rest.end()) {
            return make_pair(vec[i], target - vec[i]);
        }
        rest.emplace(target - vec[i]);
    }
    return make_pair(-1, -1);
}
