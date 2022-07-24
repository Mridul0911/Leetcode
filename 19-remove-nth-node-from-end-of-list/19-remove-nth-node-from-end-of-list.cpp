class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         ListNode *temp=head;
      int countNodes=0;
      while(temp!=NULL)
      {
          countNodes++;
          temp=temp->next;
      }
      if(countNodes==n)
      {
          return head->next;
      }
      int difference = countNodes - n;
      int counter=1;
      temp=head;
      while(counter!=difference)
      {
          counter++;
          temp=temp->next;
      }
      //ListNode *node=temp->next;
      temp->next=temp->next->next;
      //delete node;
      return head;
    }
};