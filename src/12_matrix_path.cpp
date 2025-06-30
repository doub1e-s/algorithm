//
// Created by Damon on 2025/3/26.
//

#include "my_algorithms.h"

bool FindExistPathHelper(const vector<std::vector<char>>& matrix, int row, int col, vector<vector<bool>>& visited,
    const string target, int index)
{
    // 当前char是否有必要检验
    if (row < 0 || row >= matrix.size() || col < 0 || col >= matrix[0].size() || visited[col][row]) {
        return false;
    }
    // 判断当前的char和目标char是否相同
    if (matrix[row][col] != target[index]) {
        return false;
    }
    if (index == target.size() - 1) {   // 找到了匹配的字符
        return true;
    }
    visited[row][col] = true;
    bool res = FindExistPathHelper(matrix, row + 1, col, visited, target, index + 1) ||
        FindExistPathHelper(matrix, row - 1, col, visited, target, index + 1) ||
        FindExistPathHelper(matrix, row, col + 1, visited, target, index + 1) ||
        FindExistPathHelper(matrix, row, col - 1, visited, target, index + 1);
    visited[row][col] = false;  // 回溯
    return res;
}

// 矩阵中的路径
bool FindExistPath(const std::vector<std::vector<char>>& matrix, const std::string& target)
{
    if (matrix.empty() || matrix[0].empty()) { return false; }
    if (target.empty()) { return true; }
    std::vector<std::vector<bool>> visited(matrix.size(), std::vector<bool>(matrix[0].size(), false));
    for (int row = 0; row < matrix.size(); row++) {
        for (int col = 0; col < matrix[0].size(); col++) {
            // 只有和第一个字符相同才继续判断
            if (matrix[row][col] == target[0]) {    // 起点可以是任何一个点
                if (FindExistPathHelper(matrix, row, col, visited, target, 0)) {
                    return true;
                }
            }
        }
    }
    return false;
}
