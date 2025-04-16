//
// Created by Damon on 2025/4/15.
//

#include "my_algorithms.h"

void DeleteListNode(ListNode** node, ListNode** deleteTarget)
{
    if (*node == nullptr || *deleteTarget == nullptr) { return ; }
    // 如果要删除的节点是头节点
    if (*node == *deleteTarget) {
        ListNode* newHead = (*node)->m_pNext;
        delete (*node);
        *node = newHead;
        return ;
    }
    while ((*node)->m_pNext != *deleteTarget) {
        *node = (*node)->m_pNext;
    }
    // 找到target则删除，否则直接返回
    if ((*node)->m_pNext == *deleteTarget) {
        ListNode* next = (*node)->m_pNext->m_pNext;
        delete (*node)->m_pNext;
        *deleteTarget = nullptr;
        (*node)->m_pNext = next;
    }
}
