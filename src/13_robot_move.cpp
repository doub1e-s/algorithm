//
// Created by Damon on 2025/3/27.
//

#include "my_algorithms.h"
#include <unordered_set>
#include <unordered_map>

namespace
{
// 尚未考虑负数的问题
int GetSeprateSum(int num)
{
    int ret = 0;
    while (num != 0) {
        ret += num % 10;
        num /= 10;
    }
    return ret;
}

std::unordered_map<int, std::unordered_set<int>> visitedIndex;
}

int RobotMoveRange(int row, int col, int rowBound, int colBound, int k)
{
    int rowSum = GetSeprateSum(row);
    int colSum = GetSeprateSum(col);
    // 可以考虑将上面两个变量放到边界值判定的后面，可能会减少执行的次数，降低cpu的消耗
    if (rowSum + colSum > k || row > rowBound || col > colBound ||
        (visitedIndex.find(row) != visitedIndex.end() && visitedIndex[row].find(col) != visitedIndex[row].end())) {
        return 0;
    }
    visitedIndex[row].insert(col);
    return 1 + RobotMoveRange(row+1, col, rowBound, colBound, k) + RobotMoveRange(row, col+1, rowBound, colBound, k);
}

int RobotMoveRange(int rowBound, int colBound, int k)
{
    if (k == 0) { return 0; }
    visitedIndex.clear();
    return RobotMoveRange(0, 0, rowBound, colBound, k);
}
