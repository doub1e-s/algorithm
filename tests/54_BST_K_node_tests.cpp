//
// Created by Damon on 2025/6/15.
//

#include "my_algorithms.h"
#include <gtest/gtest.h>


TEST(BSTKNodeTests, NormalTest)
{
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(3);
    root->right= new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(1);
    root->right->left = new TreeNode(6);
    root->right->left->left= new TreeNode(5);
    root->right->right= new TreeNode(8);

    EXPECT_EQ(FindLargeKNode(root, 1), 8);
    EXPECT_EQ(FindLargeKNode(root, 2), 7);
    EXPECT_EQ(FindLargeKNode(root, 3), 6);
    EXPECT_EQ(FindLargeKNode(root, 4), 5);
    EXPECT_EQ(FindLargeKNode(root, 5), 4);
    EXPECT_EQ(FindLargeKNode(root, 6), 3);
    EXPECT_EQ(FindLargeKNode(root, 7), 2);
    EXPECT_EQ(FindLargeKNode(root, 8), 1);
}

TEST(BSTKNodeTests, ExceptionTests)
{
    TreeNode* root;
    EXPECT_EQ(FindLargeKNode(root, 2), -1);
    TreeNode* root2 = new TreeNode(1);
    EXPECT_EQ(FindLargeKNode(root, 0), -1);
}