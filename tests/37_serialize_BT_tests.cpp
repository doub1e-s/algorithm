//
// Created by Damon on 2025/5/25.
//

#include "my_algorithms.h"
#include <gtest/gtest.h>

// 假设 TreeNode 和 serialize/deserialize 函数已定义（如前文所示）

TEST(SerializeDeserializeTest, EmptyTree) {
    TreeNode* root = nullptr;
    std::string serialized = SerializeBT(root);
    EXPECT_EQ(serialized, "#");  // 空树序列化为 "#"

    TreeNode* deserialized = DeSerializeBT(serialized);
    EXPECT_EQ(deserialized, nullptr);  // 反序列化后仍为 nullptr
}

TEST(SerializeDeserializeTest, SingleNode) {
    TreeNode* root = new TreeNode(1);
    std::string serialized = SerializeBT(root);
    EXPECT_EQ(serialized, "1,#,#");  // 单节点树序列化为 "1,#,#"

    TreeNode* deserialized = DeSerializeBT(serialized);
    ASSERT_NE(deserialized, nullptr);
    EXPECT_EQ(deserialized->value, 1);
    EXPECT_EQ(deserialized->left, nullptr);
    EXPECT_EQ(deserialized->right, nullptr);

    delete deserialized;  // 避免内存泄漏
}

TEST(SerializeDeserializeTest, CompleteBinaryTree) {
    /*
          1
         / \
        2   3
       / \ / \
      4  5 6 7
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    std::string serialized = SerializeBT(root);
    EXPECT_EQ(serialized, "1,2,4,#,#,5,#,#,3,6,#,#,7,#,#");

    TreeNode* deserialized = DeSerializeBT(serialized);
    ASSERT_NE(deserialized, nullptr);
    EXPECT_EQ(deserialized->value, 1);

    // 验证左子树
    ASSERT_NE(deserialized->left, nullptr);
    EXPECT_EQ(deserialized->left->value, 2);
    ASSERT_NE(deserialized->left->left, nullptr);
    EXPECT_EQ(deserialized->left->left->value, 4);
    EXPECT_EQ(deserialized->left->right->value, 5);

    // 验证右子树
    ASSERT_NE(deserialized->right, nullptr);
    EXPECT_EQ(deserialized->right->value, 3);
    ASSERT_NE(deserialized->right->left, nullptr);
    EXPECT_EQ(deserialized->right->left->value, 6);
    EXPECT_EQ(deserialized->right->right->value, 7);

    // 释放内存（实际项目中建议用智能指针）
    delete deserialized->left->left;
    delete deserialized->left->right;
    delete deserialized->left;
    delete deserialized->right->left;
    delete deserialized->right->right;
    delete deserialized->right;
    delete deserialized;
}

TEST(SerializeDeserializeTest, IncompleteBinaryTree) {
    /*
          1
         / \
        2   3
         \   \
          4   5
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(5);

    std::string serialized = serialize(root);
    EXPECT_EQ(serialized, "1,2,#,4,#,#,3,#,5,#,#");

    TreeNode* deserialized = deserialize(serialized);
    ASSERT_NE(deserialized, nullptr);
    EXPECT_EQ(deserialized->val, 1);

    // 验证左子树
    ASSERT_NE(deserialized->left, nullptr);
    EXPECT_EQ(deserialized->left->val, 2);
    EXPECT_EQ(deserialized->left->left, nullptr);  // 左子节点缺失
    ASSERT_NE(deserialized->left->right, nullptr);
    EXPECT_EQ(deserialized->left->right->val, 4);

    // 验证右子树
    ASSERT_NE(deserialized->right, nullptr);
    EXPECT_EQ(deserialized->right->val, 3);
    EXPECT_EQ(deserialized->right->left, nullptr);  // 左子节点缺失
    ASSERT_NE(deserialized->right->right, nullptr);
    EXPECT_EQ(deserialized->right->right->val, 5);

    // 释放内存
    delete deserialized->left->right;
    delete deserialized->right->right;
    delete deserialized->left;
    delete deserialized->right;
    delete deserialized;
}