//
// Created by Damon on 2025/5/22.
//

#include "my_algorithms.h"
#include <gtest/gtest.h>

using namespace std;

// 辅助函数：比较两个 vector<vector<int>> 是否相等
bool comparePaths(const vector<vector<int>>& a, const vector<vector<int>>& b) {
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i].size() != b[i].size()) return false;
        for (size_t j = 0; j < a[i].size(); ++j) {
            if (a[i][j] != b[i][j]) return false;
        }
    }
    return true;
}

// 测试用例
TEST(PathSumTest, NormalCase) {
    /*
          5
         / \
        4   8
       /   / \
      11  13  4
     /  \    / \
    7    2  5   1
    */
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    vector<vector<int>> expected = {
        {5, 4, 11, 2},
        {5, 8, 4, 5}
    };

    vector<vector<int>> result = TreeNodeSumTrace(root, 22);
    EXPECT_TRUE(comparePaths(result, expected));

    // 释放内存（实际项目中建议用智能指针）
    delete root->right->right->right;
    delete root->right->right->left;
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->left->right;
    delete root->left->left->left;
    delete root->left->left;
    delete root->left;
    delete root;
}


TEST(PathSumTest, SinglePath) {
    /*
          1
         / \
        2   3
       /
      4
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    vector<vector<int>> expected = {
        {1, 2, 4}
    };

    vector<vector<int>> result = TreeNodeSumTrace(root, 7); // 1 + 2 + 4 = 7
    EXPECT_TRUE(comparePaths(result, expected));

    // 释放内存
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;
}

TEST(PathSumTest, NoPath) {
    /*
          1
         / \
        2   3
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    vector<vector<int>> expected = {};

    vector<vector<int>> result = TreeNodeSumTrace(root, 10); // 没有路径和为 10
    EXPECT_TRUE(comparePaths(result, expected));

    // 释放内存
    delete root->left;
    delete root->right;
    delete root;
}

TEST(PathSumTest, EmptyTree) {
    TreeNode* root = nullptr;

    vector<vector<int>> expected = {};

    vector<vector<int>> result = TreeNodeSumTrace(root, 0);
    EXPECT_TRUE(comparePaths(result, expected));
}

TEST(PathSumTest, SingleNode) {
    /*
        5
    */
    TreeNode* root = new TreeNode(5);

    vector<vector<int>> expected = {
        {5}
    };

    vector<vector<int>> result = TreeNodeSumTrace(root, 5); // 路径和为 5
    EXPECT_TRUE(comparePaths(result, expected));

    // 释放内存
    delete root;
}