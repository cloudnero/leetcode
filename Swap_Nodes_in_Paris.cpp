/*
Swap Nodes in Pairs


Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

首先判断节点个数，如果是0-1个，直接返回head，如果大于1个，head->next是要返回的头指针。利用3个指针来做变换操作。p,q用来交换两个指针，r记录上一次交换后的位置，它的next也需要改变。
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if(head == NULL || head -> next == NULL)
            return head;
        ListNode * p = head, *q, *r = new ListNode(0);
        head = p -> next;
        while(p && (q = p-> next)){
            r -> next = q;
            p -> next = q -> next;
            q -> next = p;
            r = p;
            p = p -> next;
        }
        return head;
    }
};
