//
// Created by Damon on 2025/3/15.
//

#include "my_algorithms.h"

bool FindNumberInMatrix(const std::vector<std::vector<int>>& matrix, const int target)
{
    if (matrix.empty() || matrix[0].empty()) return false;
    int row = 0;    // 行
    int col = matrix[0].size() - 1;    // 列
    while (row < matrix.size() && col >= 0) {
        if (matrix[row][col] == target) {
            return true;
        }
        if (matrix[row][col] > target) {
            col--;
        } else if (matrix[row][col] < target) {
            row++;
        }
    }
    return false;
}