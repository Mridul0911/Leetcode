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
    ListNode* mergeNodes(ListNode* head) {
       // ListNode * temp = head , *temp2 = head , *prev;
       //  int sum = 0;
       //  while(temp)
       //  {
       //      while(temp->val != 0)
       //      {
       //          sum += temp->val;
       //          temp = temp->next;
       //      }
       //      if(sum != 0) 
       //      {
       //          temp2->val = sum;
       //          prev = temp2; 
       //          temp2 = temp2->next;
       //          sum = 0;
       //      }
       //      temp = temp->next;
       //  }
       //  prev->next = NULL;
       //  return head;
            ios_base::sync_with_stdio(0);
cin.tie(0); cout.tie(0);

        ListNode* res = new ListNode(0);
        ListNode* ret = res;
        int sm = 0;
        head = head->next;
        while(head != NULL)
        {
            if(head->val == 0)
            {
                res->next = new ListNode(sm);
                res = res->next;
                sm = 0;
            } 
            else 
            {
                sm += head->val;
            }
            head = head->next;
        }
        return ret->next;
    }
};