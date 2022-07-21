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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
      ListNode *temp=head;
	ListNode *prev=head;
	for(int i=0;i<left-1;i++)    temp=temp->next;
	ListNode *node=temp;
	vector<int>v;
	for(int i=0;i<(right-left+1);i++){
		v.push_back(node->val);
		node=node->next;
	}
	reverse(v.begin(),v.end());
	 for(int i = 0; i < v.size(); i++){
		temp->val = v[i];
		temp = temp->next;
	}
	return head;
    }
};