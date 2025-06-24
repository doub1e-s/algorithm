//
// Created by Damon on 2025/3/15.
//

#include "my_algorithms.h"

// 04 在二维数组中查找是否有指定的数字，每一行从左到右递增，从上到下递增
bool FindNumberInMatrix(const std::vector<std::vector<int>>& matrix, const int target)
{
    if (matrix.empty() || matrix.front().empty()) {
        return false;
    }
    int row = 0;
    int col = matrix.front().size() - 1;
    while (row < matrix.size() && col >= 0) {
        if (matrix[row][col] > target) {
            col--;
        } else if (matrix[row][col] < target) {
            row++;
        } else {
            return true;
        }
    }
    return false;
}