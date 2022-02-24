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
    ListNode* sortList(ListNode* head) {
            ListNode *newNode=head;
            
        vector<int> ans;
            while(newNode!=NULL)
            {
                    ans.push_back(newNode->val);
                    newNode=newNode->next;
            }
            sort(ans.begin(),ans.end());
            newNode=head;
            int index=0;
            while(newNode!=NULL)
            {
                    newNode->val=ans[index++];
                    newNode=newNode->next;
            }
            return head;
             
    }
};