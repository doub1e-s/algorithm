//
// Created by Damon on 2025/5/17.
//

#include "my_algorithms.h"
#include <gtest/gtest.h>

TEST(SymmertricTree, NormalTest)
{
    TreeNode* tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(2);
    // tree1->left->left = new TreeNode(4);
    // tree1->left->right = new TreeNode(5);
    // tree1->right->left = new TreeNode(6);
    // tree1->right->right = new TreeNode(7);

    EXPECT_EQ(SymmertricTree(tree1), true);

    tree1->left->value = 3;
    EXPECT_EQ(SymmertricTree(tree1), false);
}