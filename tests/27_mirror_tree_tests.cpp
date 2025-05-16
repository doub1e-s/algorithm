//
// Created by Damon on 2025/5/16.
//

#include "my_algorithms.h"
#include <gtest/gtest.h>
#include <iostream>
#include <queue>

using namespace std;

vector<vector<int>> LayerOrderTraverse(TreeNode* root)
{
    if (root == nullptr) return {};
    vector<vector<int>> layer;
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);
    while (!nodeQueue.empty()) {
        vector<int> curLayer;
        size_t curSize = nodeQueue.size();
        for (auto i = 0; i < curSize; i++) {
            TreeNode* curNode = nodeQueue.front();
            curLayer.push_back(curNode->m_value);
            if (curNode->m_pLeft) {
                nodeQueue.push(curNode->m_pLeft);
            }
            if (curNode->m_pRight) {
                nodeQueue.push(curNode->m_pRight);
            }
            nodeQueue.pop();
        }
        layer.push_back(curLayer);
    }
    return layer;
}

TEST(MirrorTreeTests, NormalTests)
{
    TreeNode* tree1 = new TreeNode(3);
    tree1->m_pLeft = new TreeNode(4);
    tree1->m_pRight = new TreeNode(5);
    tree1->m_pLeft->m_pLeft = new TreeNode(1);
    tree1->m_pLeft->m_pRight = new TreeNode(2);
    tree1->m_pRight->m_pLeft = new TreeNode(6);
    tree1->m_pRight->m_pRight = new TreeNode(7);
    MirrorTreeNode(tree1);
    vector<vector<int>> layer = LayerOrderTraverse(tree1);
    cout << "simple test layer.size  " << layer.size() << endl;
    for (auto i = 0; i < layer.size(); i++) {
        for (auto j = 0; j < layer[i].size(); j++) {
            std::cout << layer[i][j] << " ";
        }
        std::cout << endl;
    }
}