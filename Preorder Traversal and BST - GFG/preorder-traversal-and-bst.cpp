// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++


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
    bool find(Node *root,Node *min,Node *max)
    {
        if(root==NULL)
        {
            return true;
        }
        if(min!=NULL && root->data<=min->data)
        {
            return false;
        }
         if(max!=NULL && root->data>=max->data)
        {
            return false;
        }
        bool leftValid=find(root->left,min,root);
        bool rightValid=find(root->right,root,max);
        return leftValid&&rightValid;
    }
    int canRepresentBST(int arr[], int N) 
    {
        stack<int>stk;
        int root=INT_MIN;
        for(int i=0;i<N;i++)
        {
            while(!stk.empty() && arr[i]>stk.top())
            {
                root=stk.top();
                stk.pop();
            }
            if(arr[i]<root)
            {
                return 0;
            }
            stk.push(arr[i]);
        }
        
        return 1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        Solution ob;
        cout << ob.canRepresentBST(arr, N) << endl;
    }
    return 0;
}  // } Driver Code Ends