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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *left=head;
        ListNode *right=head;
        ListNode *curr=head;
        int count=1;
        while(curr!=NULL)
        {
            if(count<k)
            {
                left=left->next;
            }
            if(count>k)
            {
                right=right->next;
            }
            count++;
            curr=curr->next;
        }
        swap(left->val,right->val);
        return head;
     }
};