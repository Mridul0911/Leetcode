class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
              return head;
        }
        ListNode *temp;
        temp=head->next;
        head->next=swapPairs(head->next->next);
        temp->next=head;
        return temp;
        
        // vector<int> inp;
        // ListNode *gg=head;
        // while(gg!=NULL)
        // {
        //     inp.push_back(gg->val);
        //     gg=gg->next;
        // }
        // for(int i=0;i<inp.size();i+=2)
        // {
        //     if(i==inp.size()-1)
        //     {
        //         break;
        //     }
        //     swap(inp[i],inp[i+1]);
        // }
        // ListNode *finallist=new ListNode(-1);
        // ListNode *hh=finallist;
        // for(int i=0;i<inp.size();i++)
        // {
        //     finallist->next=new ListNode(inp[i]);
        //     finallist=finallist->next;
        // }
        // return hh->next;
    }
};