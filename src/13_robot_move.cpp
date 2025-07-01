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

 std::unordered_map<int, std::unordered_set<int>> visitedIndex;  // 如果不限制在一个m*n的棋盘中，就应该使用这种容器的形式
}

int RobotMoveRangeHelper(int row, int col, int rowBound, int colBound, int k, vector<vector<bool>>& visited)
{
    if (row > rowBound || row < 0 || col < 0 || col > colBound ||
        GetSeprateSum(row) + GetSeprateSum(col) > k || visited[row][col]) {
        return 0;
    }
    visited[row][col] = true;
    return 1 + RobotMoveRangeHelper(row + 1, col, rowBound, colBound, k, visited) +
        RobotMoveRangeHelper(row - 1, col, rowBound, colBound, k, visited) +
        RobotMoveRangeHelper(row, col - 1, rowBound, colBound, k, visited) +
        RobotMoveRangeHelper(row, col + 1, rowBound, colBound, k, visited);
}

/*
 *  机器人只能走按位相加的和的长度的范围请问他能走多少个格子,例如，12,34，最终的k值和为10.
 *  20虽然相加等于2，但是他需要从19走过去，不能闪烁，所以应该通过递归的形式去计算所有能访问的总数
 */
int RobotMoveRange(int rowBound, int colBound, int k)
{
    if (k == 0 || rowBound <= 0 || colBound<= 0) { return 0; }
    vector<vector<bool>> visited(rowBound + 1, vector<bool>(colBound + 1, false));
    return RobotMoveRangeHelper(0, 0, rowBound, colBound, k, visited);
}
