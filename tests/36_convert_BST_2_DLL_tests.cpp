//
// Created by Damon on 2025/5/23.
//

#include "my_algorithms.h"
#include <gtest/gtest.h>

// 辅助函数：打印双向链表（正向）
void printDLLForward(TreeNode* head) {
    while (head) {
        std::cout << head->value << " ";
        head = head->right;
    }
    std::cout << std::endl;
}

// 辅助函数：打印双向链表（反向）
void printDLLBackward(TreeNode* tail) {
    while (tail) {
        std::cout << tail->value << " ";
        tail = tail->left;
    }
    std::cout << std::endl;
}

// 辅助函数：释放双向链表内存
void freeDLL(TreeNode* head) {
    while (head) {
        TreeNode* temp = head;
        head = head->right;
        delete temp;
    }
}

// 测试用例
TEST(BSTToDLLTest, NormalCase) {
    /*
          4
         / \
        2   5
       / \
      1   3
    */
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    TreeNode* head = ConvertBSTToDLL(root);

    // 验证双向链表是否正确
    EXPECT_EQ(head->value, 1);  // 头节点是最小值
    EXPECT_EQ(head->right->value, 2);
    EXPECT_EQ(head->right->right->value, 3);
    EXPECT_EQ(head->right->right->right->value, 4);
    EXPECT_EQ(head->right->right->right->right->value, 5);

    // 验证反向链表是否正确
    TreeNode* tail = head;
    while (tail && tail->right) {
        tail = tail->right;
    }
    EXPECT_EQ(tail->value, 5);  // 尾节点是最大值
    EXPECT_EQ(tail->left->value, 4);
    EXPECT_EQ(tail->left->left->value, 3);
    EXPECT_EQ(tail->left->left->left->value, 2);
    EXPECT_EQ(tail->left->left->left->left->value, 1);

    // 打印验证（可选）
    std::cout << "Forward: ";
    printDLLForward(head);  // 输出: 1 2 3 4 5
    std::cout << "Backward: ";
    printDLLBackward(tail); // 输出: 5 4 3 2 1

    // 释放内存
    freeDLL(head);

    // 注意：原树结构已被修改，这里不再单独释放原树节点
}