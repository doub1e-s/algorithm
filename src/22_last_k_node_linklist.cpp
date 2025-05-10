//
// Created by Damon on 25-5-11.
//

#include <my_algorithms.h>

ListNode* GetLastKNode(ListNode* head, int k)
{
    if (head == nullptr || k <= 0) {
        return nullptr;
    }
    // 如果k大于head的总长度，则直接返回head
    ListNode* tail = head;
    while (k > 0 && tail != nullptr) {
        tail = tail->m_pNext;
        k--;
    }
    if (tail == nullptr) {
        return head;
    }
    while (tail != nullptr) {
        tail = tail->m_pNext;
        head = head->m_pNext;
    }
    return head;
}
