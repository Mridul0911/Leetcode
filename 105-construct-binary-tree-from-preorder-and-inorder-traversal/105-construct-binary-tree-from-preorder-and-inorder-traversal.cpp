class Solution {
public:
      int idx;
int search(vector<int> in,int start,int end,int val)
{
    for(int i=start;i<=end;i++)
    {
        if(in[i]==val)
        {
            return i;
        }
    }
    return -1;
}
TreeNode * helper(vector<int> pre,vector<int> in,int start,int end)
{
    if(start>end)
    {
        return NULL;
    }
    int val=pre[idx];
    idx++;
    TreeNode *curr=new TreeNode(val);
    if(start==end)
    {
      return curr;  
    }
    int pos=search(in,start,end,val);
    curr->left=helper(pre,in,start,pos-1);
    curr->right=helper(pre,in,pos+1,end);
    return curr;
}
 TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        idx=0;
       return helper(preorder,inorder,0,preorder.size()-1);    
    }
};