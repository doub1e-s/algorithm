//
// Created by Damon on 2025/3/13.
//

#include "my_algorithms.h"
#include <unordered_set>

int FindRepetitionNumber(const std::vector<int>& vec)
{
    std::unordered_set<int> findedSet;
    for (auto it : vec) {
        if (findedSet.find(it) != findedSet.end()) {
            return it;
        }
        findedSet.insert(it);
    }
    return -1;    // 异常场景返回
}