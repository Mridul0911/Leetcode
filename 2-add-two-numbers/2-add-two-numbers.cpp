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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         int carry=0,first=0,second=0;
        
        ListNode *ans=new ListNode(),*tail=ans;
                while(l1 || l2 || carry)
                {
                        if(l1)
                        {
                                first=l1->val;
                                l1=l1->next;
                        }
                        else
                        {
                                first=0;
                        }
                        if(l2)
                        {
                                second=l2->val;
                                l2=l2->next;
                        }
                        else
                        {
                                second=0;
                        }
                        int finalans=first+second+carry;
                        tail->next=new ListNode(finalans%10);
                        tail=tail->next;
                        carry=finalans/10;
                   }
            return ans->next;
    }
};