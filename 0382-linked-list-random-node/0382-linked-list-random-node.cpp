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