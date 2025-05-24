//
// Created by Damon on 2025/5/23.
//

#include "my_algorithms.h"

// 需要注意prev和head是需要向下递归确认返回的，所以是需要作为引用形式
void InorderConvert(TreeNode* cur, TreeNode*& prev, TreeNode*& head)
{
    if (!cur) { return; }
    InorderConvert(cur->left, prev, head);

    cur->left = prev;
    if (prev == nullptr) {
        head = cur;
    } else {
        // 因为是双向链表，所以一定要让前一个节点指向当前节点
        prev->right = cur;
    }
    prev = cur;
    InorderConvert(cur->right, prev, head);
}

TreeNode* ConvertBSTToDLL(TreeNode* root)
{
    if (root == nullptr) { return nullptr; }
    TreeNode* prev = nullptr;
    TreeNode* head= nullptr;
    InorderConvert(root, prev, head);
    return head;
}
