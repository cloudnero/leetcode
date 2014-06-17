/*
Remove Nth Node From End of List


Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.
Try to do this in one pass.
*/
    ListNode * p, *q = new ListNode(0), *r;
        q -> next = head;
        p = head;
        for(int i = 0; i < n; i++){  //将一个指针走n步
            p = p -> next;
        }
        if(p == NULL){               //如果已经到了尾部，说明要删除头结点
            return head -> next;
        }
        r = head;
        while(p){
            head = head -> next;
            q = q -> next;
            p = p -> next;
        }
        q -> next = head -> next;
        delete head;
        return r;
    }
