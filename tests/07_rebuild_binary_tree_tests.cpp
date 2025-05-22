//
// Created by Damon on 2025/3/19.
//

#include <gtest/gtest.h>
#include "my_algorithms.h"

void InOrderTraverse(TreeNode* root, std::vector<int>& inOrder)
{
    if (root == nullptr) { return; }
    InOrderTraverse(root->left, inOrder);
    inOrder.push_back(root->value);
    InOrderTraverse(root->right, inOrder);
}

TEST(RebuildBinaryTreeTests, EmptyTree)
{
    std::vector<int> inOrder;
    std::vector<int> preOrder;
    TreeNode* root = ReBuildBinaryTree(inOrder, preOrder);
    EXPECT_EQ(nullptr, root);
}

TEST(RebuildBinaryTreeTests, ValidExample)
{
    std::vector<int> inOrder {3, 9, 20, 15, 7};
    std::vector<int> preOrder {9, 3, 15, 20, 7};
    TreeNode* root = ReBuildBinaryTree(preOrder, inOrder);
    std::vector<int> result;
    InOrderTraverse(root, result);
    EXPECT_EQ(inOrder, result);
}