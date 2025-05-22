//
// Created by Damon on 2025/5/22.
//

#include "my_algorithms.h"
#include <map>

ComplexNode* CopyComplexNode(ComplexNode* head)
{
    if (head == nullptr) { return nullptr; }
    ComplexNode* cur = head;
    map<ComplexNode*, ComplexNode*> origin2Copy;
    while (cur) {
        origin2Copy[cur] = new ComplexNode(cur->value);
        cur = cur->next;
    }

    for (auto it = origin2Copy.begin(); it != origin2Copy.end(); it++) {
        it->second->next = it->first->next;
        it->second->sibling = origin2Copy[it->first->sibling];
    }
    return origin2Copy[head];   // 不可以使用begin()，因为map是排序之后的
}
