#include"functions.h"


//请编写一个函数，用于 删除单链表中某个特定节点 。在设计函数时需要注意，你无法访问链表的头节点 head ，只能直接访问 要被删除的节点 。

//题目数据保证需要删除的节点 不是末尾节点 。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode* next;
    //默认构造：构造函数初始值列表
    ListNode(int x) : val(x), next(NULL) {}
};


void deleteNode(ListNode* node) {
    //浅拷贝
    *node = *node->next;
    //在给定节点node的情况下，可以通过修改node的next指针的指向，删除node的下一个节点。
    //但是题目要求删除node，为了达到删除node的效果，只要在删除节点之前，将node的节点值修改为node.next的节点值即可。

    //node->val = node->next->val;
    //node->next = node->next->next;
}
