//
// Created by Damon on 2025/3/26.
//

#include "my_algorithms.h"

bool FindExistPath(const std::vector<std::vector<char>>& matrix, int row, int col,
    std::vector<std::vector<bool>>& visited, std::string target, int index)
{
    if (index == target.size()) { return true; }
    // 超过边界
    if (row < 0 || row >= matrix.size() || col < 0 || col >= matrix[0].size()) { return false; }
    // 已经访问过或者和target目标不同
    if (matrix[row][col] != target[index] || visited[row][col]) { return false; }
    visited[row][col] = true;
    bool exists = FindExistPath(matrix, row - 1, col, visited, target, index + 1) ||
        FindExistPath(matrix, row + 1, col, visited, target, index + 1) ||
        FindExistPath(matrix, row, col - 1, visited, target, index + 1) ||
        FindExistPath(matrix, row, col + 1, visited, target, index + 1);
    visited[row][col] = false;
    return exists;
}

bool FindExistPath(const std::vector<std::vector<char>>& matrix, const std::string& target)
{
    if (matrix.empty() || matrix[0].empty()) { return false; }
    if (target.empty()) { return true; }
    std::vector<std::vector<bool>> visited(matrix.size(), std::vector<bool>(matrix[0].size(), false));
    for (int row = 0; row < matrix.size(); row++) {
        for (int col = 0; col < matrix[0].size(); col++) {
            // 只有和第一个字符相同才继续判断
            if (matrix[row][col] == target[0]) {
                if (FindExistPath(matrix, row, col, visited, target, 0)) {
                    return true;
                }
            }
        }
    }
    return false;
}
