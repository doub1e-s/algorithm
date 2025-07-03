//
// Created by Damon on 25-5-11.
//

#include <my_algorithms.h>

ListNode* GetLoopLinkListEntryNode(ListNode* head)
{
    if (head == nullptr) { return nullptr; }
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow) {
            break;
        }
    }
    if (fast == nullptr || fast->next == nullptr) { return nullptr; }   // 不存在环
    // 初始值设置为下一个节点，并且将当前size初始值设置为1
    ListNode* curNode = slow->next;
    int loopSize = 1;
    while (curNode != slow) {
        loopSize++;
        curNode = curNode->next;
    }
    curNode = head;
    fast = head;
    for (int i = 0; i < loopSize; i++) {
        fast = fast->next;
    }
    while (curNode != fast) {
        curNode = curNode->next;
        fast = fast->next;
    }
    return curNode;
}
