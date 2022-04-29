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
        ListNode *tmp2=head , *tmp3=head, *tmp1;
        int num=k;
        while(num>1)
        {
            tmp3=tmp3->next;
            num--;
        }
        tmp1=tmp3;
        while(tmp3->next)
        {
            tmp2=tmp2->next;
            tmp3=tmp3->next;
        }
        swap(tmp1->val,tmp2->val);
        return head;
    }
};