/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
        int len=0;
        ListNode *list;
        
    Solution(ListNode* head) {
        list=head;
            ListNode *bb=head;
            while(bb)
            {
                    len++;
                    bb=bb->next;
            }
            
    }
    
    int getRandom() {
        int index=rand()%len;
            ListNode *ptr=list;
            for(int i=0;i<index;i++)
            {
                    ptr=ptr->next;
            }
            return ptr->val;
           
            
            
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */