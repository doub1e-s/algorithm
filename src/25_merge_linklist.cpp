//
// Created by Damon on 2025/5/12.
//

#include <my_algorithms.h>

ListNode* Merge(ListNode* list1, ListNode* list2)
{
    if (!list1) { return list2; }
    if (!list2) { return list1; }
    ListNode* head = nullptr;
    if (list1->value < list2->value) {
        head = list1;
        list1 = list1->next;
    } else {
        head = list2;
        list2 = list2->next;
    }
    ListNode* cur = head;
    while (list1 && list2) {
        if (list1->value < list2->value) {
            cur->next = list1;
            cur = cur->next;
            list1 = list1->next;
        } else {
            cur->next = list2;
            cur = cur->next;
            list2 = list2->next;
        }
    }
    while (list1) {
        cur->next = list1;
        cur = cur->next;
        list1 = list1->next;
    }
    while (list2) {
        cur->next = list2;
        cur = cur->next;
        list2 = list2->next;
    }
    return head;
}