//
// Created by Damon on 2025/5/19.
//

#include "my_algorithms.h"
#include <gtest/gtest.h>

using namespace std;

TEST(LayerOrderPrintTreeTests, Normal)
{
    TreeNode* node1 = new TreeNode(1);
    node1->m_pLeft = new TreeNode(2);
    node1->m_pRight = new TreeNode(3);
    node1->m_pLeft->m_pLeft = new TreeNode(4);
    node1->m_pLeft->m_pRight = new TreeNode(5);
    node1->m_pRight->m_pLeft = new TreeNode(6);
    node1->m_pRight->m_pRight = new TreeNode(7);
}