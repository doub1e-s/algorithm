//
// Created by Damon on 2025/5/12.
//

#include <my_algorithms.h>

ListNode* Merge(ListNode* list1, ListNode* list2)
{
    if (!list1) { return list2; }
    if (!list2) { return list1; }
    ListNode* head = nullptr;
    if (list1->m_value < list2->m_value) {
        head = list1;
        list1 = list1->m_pNext;
    } else {
        head = list2;
        list2 = list2->m_pNext;
    }
    ListNode* cur = head;
    while (list1 && list2) {
        if (list1->m_value < list2->m_value) {
            cur->m_pNext = list1;
            cur = cur->m_pNext;
            list1 = list1->m_pNext;
        } else {
            cur->m_pNext = list2;
            cur = cur->m_pNext;
            list2 = list2->m_pNext;
        }
    }
    while (list1) {
        cur->m_pNext = list1;
        cur = cur->m_pNext;
        list1 = list1->m_pNext;
    }
    while (list2) {
        cur->m_pNext = list2;
        cur = cur->m_pNext;
        list2 = list2->m_pNext;
    }
    return head;
}