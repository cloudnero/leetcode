/*
Merge k Sorted Lists


Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

以前做的ac，结果前几天提交发现超时了，原来系统最近又加了一个test case。。。用的选择排序，时间复杂度是O(n^2)

采用最小堆，首先将 k 个首节点放入堆中，弹出最小的节点并插入到新的链表中；

                     弹出的节点如果next 非空，就将它的 下一个节点进 堆。

                     继续，直到堆为空。

堆 Push 和 pop 的复杂度是 log(k), 所以复杂度是 nlg(k), n为总的节点数
&/
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int K = lists.size();
        if (K == 0) return NULL;
        else if (K == 1) return lists[0];
        
        ListNode *listHead(NULL), *listRear(NULL);
        ListNode *node(NULL);
        priority_queue<ListNode*, vector<ListNode*>, cmp> h;
        
        // push K list heads into heap
        for(int i=0; i<K; ++i)
          if(lists[i] != NULL){
            h.push(lists[i]);
            lists[i] = lists[i]->next;
          }
            
        while(!h.empty()){
          //pop the min of k nodes
          node = h.top(); h.pop();
          if(node->next)
            h.push(node->next);
            
          //insert node into new list    
          if(listRear){
              listRear->next = node;
              listRear = listRear->next;
          }
          else{
              listHead = listRear = node;
          }
        }
        
        return listHead;
    }
private:
    struct cmp{
        bool operator()(ListNode* lhs, ListNode *rhs){
            if(lhs->val < rhs->val) return false;
            else return true;
        }
    };
};
