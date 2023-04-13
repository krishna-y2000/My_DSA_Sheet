

// LinkedList: 1->2->2->4->5->6
// K = 4
// Output: 4 2 2 1 5 6

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
         ListNode* node = head;
        int count = 0;
        while (count < k) { 
            if(node == NULL)return head;
            node = node->next;
            count++;
        }
        // 2->reverse k node at current level 
           ListNode* pre = reverseKGroup(node, k); //pre node point to the the answer of sub-problem 
            while (count > 0) {  
                ListNode* next = head->next; 
                head->next = pre; 
                pre = head; 
                head = next;
                count = count - 1;
            }
            return pre;
    }
};