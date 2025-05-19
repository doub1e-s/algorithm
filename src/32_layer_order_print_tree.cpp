//
// Created by Damon on 2025/5/19.
//

#include "my_algorithms.h"
#include <queue>

std::vector<std::vector<int>> LayerOrder(TreeNode* head)
{
    if (head == nullptr) { return {}; }
    std::vector<std::vector<int>> layerResult;
    std::queue<TreeNode*> myQueue;
    myQueue.push(head);
    while (!myQueue.empty()) {
        std::vector<int> vec;
        size_t queueSize = myQueue.size();
        for (size_t i = 0; i < queueSize; i++) {
            vec.push_back(myQueue.front()->m_value);
            if (myQueue.front()->m_pLeft) {
                myQueue.push(myQueue.front()->m_pLeft);
            }
            if (myQueue.front()->m_pRight) {
                myQueue.push(myQueue.front()->m_pRight);
            }
            myQueue.pop();
        }
        layerResult.push_back(vec);
    }
    return layerResult;
}
