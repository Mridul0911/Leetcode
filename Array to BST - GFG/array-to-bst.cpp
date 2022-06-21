// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int x)
    {
        data=x;
        left=NULL;
        right=NULL;
    }
};
    Node *solve(vector<int> &nums,int l,int h)
    {
        if(l>h)
        {
            return NULL;
        }
        int mid=(l+h)/2;
        Node *node=new Node(nums[mid]);
        node->left=solve(nums,l,mid-1);
        node->right=solve(nums,mid+1,h);
        return node;
    }
    
    void post(Node *root,vector<int> &ans)
    {
        if(root==NULL)
        {
            return;
        }
        ans.push_back(root->data);
        post(root->left,ans);
        post(root->right,ans);
    }
    vector<int> sortedArrayToBST(vector<int>& nums) {
        // Code here
        int n=nums.size();
         Node *root=solve(nums,0,n-1);
         vector<int> ans;
        post(root,ans);
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends