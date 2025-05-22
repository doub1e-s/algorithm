//
// Created by Damon on 2025/4/15.
//

#include "my_algorithms.h"

void DeleteListNode(ListNode** node, ListNode** deleteTarget)
{
    if (*node == nullptr || *deleteTarget == nullptr) { return ; }
    // 如果要删除的节点是头节点
    if (*node == *deleteTarget) {
        ListNode* newHead = (*node)->next;
        delete (*node);
        *node = newHead;
        return ;
    }
    while ((*node)->next != *deleteTarget) {
        *node = (*node)->next;
    }
    // 找到target则删除，否则直接返回
    if ((*node)->next == *deleteTarget) {
        ListNode* next = (*node)->next->next;
        delete (*node)->next;
        *deleteTarget = nullptr;
        (*node)->next = next;
    }
}
