/*
You are given two linked lists representing two non-negative numbers.
The digits are stored in reverse order and each of their nodes contain
a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *p = new ListNode(0);
        ListNode *head = p;
        int sum = 0;
        while(l1 || l2){
            if(l1){
                sum += l1 -> val;
                l1 = l1 -> next;
            }
            if(l2){
                sum += l2 -> val;
                l2 = l2 -> next;
            }
            p -> next = new ListNode(sum % 10);
            p = p -> next;
            sum /= 10;
        }
        if(sum)
            p -> next = new ListNode(sum);
        return head -> next;
    }
