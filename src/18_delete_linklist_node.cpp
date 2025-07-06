//
// Created by Damon on 2025/4/15.
//

#include "my_algorithms.h"

// 在O(1)时间内，删除链表的节点，这里只能使用指针的指针，当deleteTarget为目标删除值的时候，需要将其置为nullptr
// 这种写法仅限于通过head访问链表节点，否则如果如果直接访问deleteTarget->next，会出现访问也空指针的问题(里面的内容已经被delete掉了)
void DeleteListNode(ListNode** node, ListNode** deleteTarget)
{
    if (node == nullptr || *node == nullptr || deleteTarget == nullptr || *deleteTarget == nullptr) { return ; }
    ListNode* nextPtr = (*deleteTarget)->next;
    if (nextPtr == nullptr) {
        delete (*deleteTarget);
        *deleteTarget = nullptr;
        return ;
    }
    // 将next对应的信息赋值给当前节点
    (*deleteTarget)->value = (*deleteTarget)->next->value;
    (*deleteTarget)->next = (*deleteTarget)->next->next;
    delete (nextPtr);
    *deleteTarget = nullptr;
}
