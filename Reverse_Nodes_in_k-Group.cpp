/*
Reverse Nodes in k-Group


Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

与swap nodes in pairs类似,上一题其实就是这题的特殊情况，k=2;只是这题k随机。还有要注意的是当节点个数不满足k的时候，不需要在转换节点位置，为此需要在最后做出判断，如果节点个数不够，需要在重新转换过来。
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head == NULL || head -> next == NULL || k == 1)
            return head;
        ListNode * p = head, *q, *r = new ListNode(0);
        r -> next = head;
        int num = 0;
        while(p && (q = p -> next)){
            p -> next = q -> next;
            q -> next = r -> next;
            r -> next = q;
            num++;
            if(num % (k-1) == 0){
                if(num == k-1)
                    head = r -> next;
                r = p;
                p = p -> next;
            }
        }
        if(num % (k-1) != 0){
            p = r -> next;
            while(p && (q = p -> next)){
                p -> next = q -> next;
                q -> next = r -> next;
                r -> next = q;
            }
        }
        
        return head;
    }
};
