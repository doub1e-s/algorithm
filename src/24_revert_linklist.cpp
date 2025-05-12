//
// Created by Damon on 2025/5/12.
//

#include <my_algorithms.h>

ListNode* RevertLinkList(ListNode* head)
{
    if (head == nullptr) {
        return nullptr;
    }
    ListNode* prev = nullptr;
    ListNode* cur = head;
    ListNode* next = nullptr;
    while (cur != nullptr) {
        next = cur->m_pNext;
        cur->m_pNext = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
