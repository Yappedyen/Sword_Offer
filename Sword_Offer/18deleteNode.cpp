#include"functions.h"

//给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
//
//返回删除后的链表的头节点。

ListNode* deleteNode(ListNode* head, int val) {
    if (head == nullptr) {
        return nullptr;
    }
    if (head->val == val) {
        return head->next;
    }
    auto pre = head, cur = head->next;
    while (cur != nullptr && cur->val != val) {
        pre = cur;
        cur = cur->next;
    }
    if (cur != nullptr) {
        pre->next = cur->next;
    }

    return head;
}