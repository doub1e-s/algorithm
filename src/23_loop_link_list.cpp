//
// Created by Damon on 25-5-11.
//

#include <my_algorithms.h>

ListNode* GetLoopLinkListEntryNode(ListNode* head)
{
    if (head == nullptr) {
        return nullptr;
    }
    ListNode* fast = head;
    ListNode* slow = head;
    while (slow != nullptr && slow->next != nullptr) {
        slow = slow->next;
        if (slow->next == nullptr) {
            return nullptr;
        }
        slow = slow->next;
        fast = fast->next;
        if (slow == fast) {
            break;  // 能够追上说明有环，此时s
        }
    }
    // 说明当前是存在环，则使用快慢指针确认环的长度
    int circleSize = 0;
    do {
        fast = fast->next;
        slow = slow->next;
        slow = slow->next;
        circleSize += 2;
    } while (fast != slow);
    fast = head;
    slow = head;
    for (int i = 0; i < circleSize; i++) {
        fast = fast->next;
    }
    while (slow != fast) {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}
