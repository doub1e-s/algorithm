#include "my_algorithms.h"
#include <gtest/gtest.h>
#include <iostream>

using namespace std;

TEST(SubTreeStructureTests, NormalTest)
{
    TreeNode* t1 = new TreeNode(1);
    t1->m_pLeft = new TreeNode(2);
    t1->m_pRight = new TreeNode(3);

    TreeNode* t2 = new TreeNode(1);
    t2->m_pLeft = new TreeNode(2);
    t2->m_pRight = new TreeNode(3);

    EXPECT_TRUE(IsSubTree(t1, t2));

    // 测试用例2：不同树
    TreeNode* t3 = new TreeNode(1);
    t3->m_pLeft = new TreeNode(2);

    TreeNode* t4 = new TreeNode(1);
    t4->m_pRight= new TreeNode(2);

    EXPECT_FALSE(IsSubTree(t3, t4));

    // 测试用例3：子树关系
    TreeNode* tree1 = new TreeNode(3);
    tree1->m_pLeft = new TreeNode(4);
    tree1->m_pRight = new TreeNode(5);
    tree1->m_pLeft->m_pLeft = new TreeNode(1);
    tree1->m_pLeft->m_pRight = new TreeNode(2);

    TreeNode* tree2 = new TreeNode(4);
    tree2->m_pLeft = new TreeNode(1);
    tree2->m_pRight = new TreeNode(2);

    // 测试用例4：空树
    EXPECT_TRUE(IsSubTree(tree1, nullptr));
    EXPECT_FALSE(IsSubTree(nullptr, tree2));
}