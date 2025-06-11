//
// Created by Damon on 2025/6/11.
//

#include "my_algorithms.h"

ListNode* FindFirstCommonNode(ListNode* l1, ListNode* l2)
{
    if (!l1 || !l2) { return nullptr; }
    ListNode* l1Ptr = l1;
    ListNode* l2Ptr = l2;
    bool l1RevertFlag = false;
    bool l2RevertFlag = false;
    while (l1Ptr && l2Ptr) {
        // 遍历结束，找到第一个公共节点
        if (l1Ptr == l2Ptr) {
            return l1Ptr;
        }
        // l1 遍历
        l1Ptr = l1Ptr->next;
        if (!l1Ptr && !l1RevertFlag) {
            l1Ptr = l2;
            l1RevertFlag = true;
        }

        // l2 遍历
        l2Ptr = l2Ptr->next;
        if (!l2Ptr && !l2RevertFlag) {
            l2Ptr = l1;
            l2RevertFlag = true;
        }
    }
    return nullptr;
}