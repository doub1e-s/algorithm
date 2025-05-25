//
// Created by Damon on 2025/5/16.
//

#include "my_algorithms.h"
#include <gtest/gtest.h>
#include "utils/test_helper.h"

using namespace std;

TEST(MirrorTreeTests, NormalTests) {
    // 构建原始树
    TreeNode* tree1 = new TreeNode(3);
    tree1->left = new TreeNode(4);
    tree1->right = new TreeNode(5);
    tree1->left->left = new TreeNode(1);
    tree1->left->right = new TreeNode(2);
    tree1->right->left = new TreeNode(6);
    tree1->right->right = new TreeNode(7);

    // 手动构建镜像后的预期树
    TreeNode* expected_tree = new TreeNode(3);
    expected_tree->left = new TreeNode(5);
    expected_tree->right = new TreeNode(4);
    expected_tree->left->left = new TreeNode(7);
    expected_tree->left->right = new TreeNode(6);
    expected_tree->right->left = new TreeNode(2);
    expected_tree->right->right = new TreeNode(1);

    // 镜像 tree1
    MirrorTreeNode(tree1);

    // 验证 tree1 是否等于 expected_tree
    EXPECT_TRUE(damon::IsSameTree(tree1, expected_tree));

    // 清理内存（实际项目中建议用智能指针）
    delete tree1->left->right;
    delete tree1->left->left;
    delete tree1->left;
    delete tree1->right->right;
    delete tree1->right->left;
    delete tree1->right;
    delete tree1;

    delete expected_tree->left->right;
    delete expected_tree->left->left;
    delete expected_tree->left;
    delete expected_tree->right->right;
    delete expected_tree->right->left;
    delete expected_tree->right;
    delete expected_tree;
}
