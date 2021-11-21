#include"functions.h"

//�������������ͷָ���һ��Ҫɾ���Ľڵ��ֵ������һ������ɾ���ýڵ㡣
//
//����ɾ����������ͷ�ڵ㡣

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