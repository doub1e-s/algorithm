//
// Created by Damon on 2025/3/19.
//
/**
 *核心思想：通过先序确认根节点的值，通过中序确认左右子树分别节点数量
 *递归的参数：先序和中序遍历的数组，因为需要递归，所以还需要两个数组的左右边界，来确认当前子树的左右边界
 *返回值：节点指针
 *跳出条件：数组中没有节点
 *另外，还需要注意，为了方便的利用中序节点的位置，使用一个map存放值和pos之间的对应关系
 *确认左右边界的时候，从当前pre/in 队列的角度去思考如何确认边界
 *
 */

#include "my_algorithms.h"
#include <unordered_map>

static std::unordered_map<int, int> inOrderValue2Ind;

TreeNode* ReBuildBinaryTree(std::vector<int>& preOrder, int preLeft, int preRight,
    std::vector<int>& inOrder, int inLeft, int inRight)
{
    if (preLeft < 0 || preLeft > preRight || preRight > preOrder.size()) { return nullptr; }
    TreeNode* root = new TreeNode(preOrder[preLeft]);
    int inOrderIndex = inOrderValue2Ind[preOrder[preLeft]];
    int leftTreeSize = inOrderIndex - inLeft;
    root->left = ReBuildBinaryTree(preOrder, preLeft + 1, preLeft + leftTreeSize,
        inOrder, inLeft, inOrderIndex - 1);
    root->right = ReBuildBinaryTree(preOrder, preLeft + leftTreeSize + 1, preRight,
        inOrder, inOrderIndex + 1, inRight);
    return root;
}

TreeNode* ReBuildBinaryTree(std::vector<int>& preOrder, std::vector<int>& inOrder)
{
    if (preOrder.empty() || inOrder.empty()) { return nullptr; }
    inOrderValue2Ind.clear();
    for (int i = 0; i < inOrder.size(); i++) { inOrderValue2Ind[inOrder[i]] = i; }
    return ReBuildBinaryTree(preOrder, 0, preOrder.size() - 1, inOrder, 0, inOrder.size() - 1);
}