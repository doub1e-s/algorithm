//
// Created by Damon on 2025/6/15.
//

#include "my_algorithms.h"
#include <gtest/gtest.h>

TEST(BTDepthTests, NormalTest)
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->left->left = new TreeNode(7);
    root->right->left->left->left = new TreeNode(8);
    EXPECT_EQ(BTDepth(root), 5);
}

TEST(BTDepthTests, ExceptionTest)
{
    TreeNode *root = nullptr;   // 野指针的情况是没办法判定的，只能考虑是否使用智能指针。
    EXPECT_EQ(BTDepth(root), 0);
}

TEST(BBTTests, NormalTest)
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    EXPECT_FALSE(IsBalanceTree(root));

    TreeNode *node1 = new TreeNode(1);
    node1->left = new TreeNode(2);
    node1->left->right = new TreeNode(7);
    node1->left->left = new TreeNode(3);
    node1->left->left->left = new TreeNode(4);
    node1->right = new TreeNode(5);
    node1->right->right = new TreeNode(6);
    EXPECT_TRUE(IsBalanceTree(node1));
}

TEST(BBTTests, ExceptionTests)
{
    TreeNode *root = nullptr;
    EXPECT_TRUE(IsBalanceTree(root));
}