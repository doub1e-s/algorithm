//
// Created by Damon on 2025/6/15.
//

#include "my_algorithms.h"
#include <set>
#include <queue>

/* 会额外使用空间
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
*/

pair<int, int> SumToTarget(vector<int> vec, int target)
{
    int smallIndex = 0;
    int bigIndex = vec.size() - 1;
    while (smallIndex < bigIndex) {
        if (vec[smallIndex] + vec[bigIndex] == target) {
            return make_pair(vec[smallIndex], vec[bigIndex]);
        } else if (vec[smallIndex] + vec[bigIndex] > target) {
            bigIndex--;
        } else {
            smallIndex++;
        }
    }
    return make_pair(-1, -1);
}

vector<vector<int>> FindContinuesSum(int target)
{
    if (target <= 2) { return {}; }
    vector<vector<int>> res;
    int start = 1;
    int end = 2;
    deque<int> curNums;
    curNums.push_back(1);
    curNums.push_back(2);
    
    int sum = start + end;
    while (start < end) {
        if (sum == target) {
            res.emplace_back(curNums.begin(), curNums.end());
            end++;
            sum += end;
            curNums.push_back(end);
        } else if (sum < target) {
            end++;
            curNums.push_back(end);
            sum += end;
        } else {
            sum -= start;
            start++;
            curNums.pop_front();
        }
    }
    return res;
}


