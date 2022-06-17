// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printInorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    void wse(Node *root,vector<int> ans,vector<pair<int,int>> &m)
    {
        if(root==NULL)
        {
            return;
        }
        ans.push_back(root->data);
        wse(root->left,ans,m);
        if(root->left==NULL && root->right==NULL)
        {
           int sum=0;
            for(int i=0;i<ans.size();i++)
            {
             sum+=ans[i];   
            }
           m.push_back({sum,ans.size()});
        }
        wse(root->right,ans,m);
        ans.pop_back();
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        int sum=0;
        vector<int> ans;
        vector<pair<int,int>> m;
        wse(root,ans,m);
        int x=0;
        int final=0;
        for(auto i:m)
        {
            if(i.second>x)
            {
                final=i.first;
                x=i.second;
            }
            if(i.second==x)
            {
                final=max(final,i.first);
            }
        }
        return final;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    scanf("%d", &t);
    cin.ignore();
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution obj;
        int res = obj.sumOfLongRootToLeafPath(root);
        cout << res << "\n";
    }
    return 0;
}  // } Driver Code Ends