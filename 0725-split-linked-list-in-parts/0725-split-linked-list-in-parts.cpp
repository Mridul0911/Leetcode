class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n=0;
        ListNode *curr=head;
        while(head!=NULL)
        {
            n++;
            head=head->next;
        }
        int per_group=n/k;
        int extra=n%k;
        vector<ListNode*> ans(k);
        for(int i=0;i<k;i++)
        {
            int total=per_group;
            if(extra>0)
            {
                total++;
                extra--;
            }
            ans[i]=curr;
            ListNode *prev=nullptr;
            while(total--) {
                prev=curr;
                curr=curr->next;
            }
            if(prev)
                prev->next=nullptr;
        }
        return ans;
    }
};
