//
// Created by Damon on 2025/3/18.
//
#include "my_algorithms.h"
#include <stack>

// 使用栈执行反向链表的打印
std::vector<int> TraverseListFromEnd(const ListNode* head)
{
    std::vector<int> result;
    std::stack<int> values;
    while (head) {
        values.push(head->m_value);
        head = head->m_pNext;
    }
    while (!values.empty()) {
        result.push_back(values.top());
        values.pop();
    }
    return result;
}

// 使用递归进行反向链表的打印
void TraverseListFromEnd(const ListNode* head, std::vector<int>& result)
{
    if (head == nullptr) { return; }
    TraverseListFromEnd(head->m_pNext, result);
    result.push_back(head->m_value);
}
