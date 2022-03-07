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
        void insert(ListNode* l3, int val)
    {
        ListNode* node=new ListNode(val);
        ListNode* temp=l3;
        
        if(l3==NULL)
        {
            l3=node;
            return;
        }
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=node;
        return;
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            if(list1==NULL && list2==NULL)
            return NULL;
        vector<int> ans;
            ListNode* head1=list1;
            ListNode* head2=list2;
            while(head1!=NULL)
            {
                    ans.push_back(head1->val);;
                    head1=head1->next;
            }
            while(head2!=NULL)
            {
                    ans.push_back(head2->val);;
                    head2=head2->next;
            }
            sort(ans.begin(),ans.end());
            ListNode *head=new ListNode(ans[0]);
            for(int i=1;i<ans.size();i++)
            {
                    insert(head,ans[i]);
            }
            return head;
     }
};