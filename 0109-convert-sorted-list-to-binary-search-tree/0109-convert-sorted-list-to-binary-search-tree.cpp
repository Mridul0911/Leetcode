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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void find(ListNode* head,vector<int> &ans)
    {
        if(head==NULL)
        {
            return;
        }
        ans.push_back(head->val);
        find(head->next,ans);
    }
    TreeNode* helper(vector<int>&v, int l, int h)
     {
        if(l>h)
            return NULL;
        int mid=l+(h-l)/2;
        TreeNode* node=new TreeNode(v[mid]);
        node->left= helper(v, l, mid-1);
        node->right=helper(v, mid+1, h);
        return node;
    }
    TreeNode* sortedListToBST(ListNode* head) 
    {
        vector<int> ans;
    
        find(head,ans);
        return helper(ans,0,ans.size()-1);
        
        
        
    }
};