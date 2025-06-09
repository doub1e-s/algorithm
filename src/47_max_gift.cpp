//
// Created by Damon on 2025/6/4.
//

#include <my_algorithms.h>

// 递归写法, 在矩阵比较大的时候，可能会出问题
/*
int MaxGiftSumHelper(const vector<vector<int>>& matrix, int row, int col)
{
    if (row < 0 || col < 0 || row >= matrix.size() || col >= matrix[0].size()) {
        return 0;
    }
    int rowMax = matrix[row][col] + MaxGiftSumHelper(matrix, row - 1, col);
    int colMax = matrix[row][col] + MaxGiftSumHelper(matrix, row, col - 1);
    return max(rowMax, colMax);
}

int MaxGiftSum(vector<vector<int>> matrix)
{
    int row = matrix.size() - 1;
    int col = matrix[0].size() - 1;
    return MaxGiftSumHelper(matrix, row, col);
}
*/

// 动态规划，即使vector比较大，还是能够很好的解决问题
int MaxGiftSum(vector<vector<int>> matrix)
{
    if (matrix.empty() || matrix[0].empty()) { return 0; }
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
    dp[0][0] = matrix[0][0];
    int maxRow = matrix.size();
    int maxCol = matrix[0].size();
    // 首行dp数据填满
    for (int row = 1; row < maxRow; row++) {
        dp[row][0] = dp[row - 1][0] + matrix[row][0];
    }
    // 首列数据填满
    for (int col = 1; col < maxCol; col++) {
        dp[0][col] = dp[0][col - 1] + matrix[0][col];
    }

    for (int row = 1; row < maxRow; row++) {
        for (int col = 1; col < maxCol; col++) {
            dp[row][col] = max(dp[row - 1][col], dp[row][col - 1]) + matrix[row][col];
        }
    }
    return dp[maxRow - 1][maxCol - 1];
}