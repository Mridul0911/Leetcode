class Solution {
public:
    vector<TreeNode*> find(int n)
    {
        if(n==1)
        {
            return {new TreeNode()};
        }
        vector<TreeNode*>currList;
        int remainingNodes=n-1;
        for(int left=1;left<=remainingNodes; left += 2) 
        {
            int right = remainingNodes - left;
            vector<TreeNode*>leftPossible = find(left);
            vector<TreeNode*>rightPossible = find(right);
            for (int i = 0; i < leftPossible.size(); i++)
            {
                for (int j = 0; j < rightPossible.size(); j++)
                {
                    TreeNode* root = new TreeNode();
                    root->left = leftPossible[i];
                    root->right = rightPossible[j];
                    currList.push_back(root);
                }
            }
        }
        return currList;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
      if(n%2==0)
      {
         return {};
      }
      vector<TreeNode*> ans=find(n);
      return ans;
    }
};