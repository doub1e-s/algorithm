//
// Created by Damon on 2025/5/19.
//

#include "my_algorithms.h"
#include <gtest/gtest.h>

using namespace std;

TEST(LayerOrderPrintTreeTests, Normal)
{
    TreeNode* node1 = new TreeNode(1);
    node1->left = new TreeNode(2);
    node1->right = new TreeNode(3);
    node1->left->left = new TreeNode(4);
    node1->left->right = new TreeNode(5);
    node1->right->left = new TreeNode(6);
    node1->right->right = new TreeNode(7);

    vector<vector<int>> layerOrder = LayerOrder(node1);
    vector<vector<int>> comp = {{1}, {2,3}, {4,5,6,7}};
    EXPECT_EQ(layerOrder, comp);
}