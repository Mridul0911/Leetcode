// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



float findMedian(struct Node* node);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));
 
   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

int main() {
  
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   //cout << t << endl;
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root = buildTree(s);

      // getline(cin, s);
       
        cout << findMedian(root) << endl;

      // cout<<"~"<<endl;
   }
   return 0;
}// } Driver Code Ends


/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// your task is to complete the Function
// Function should return median of the BST

void inorder(Node *root,int &count)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left,count);
    count++;
    inorder(root->right,count);
}
void inorderagain(Node *root,int &k,int &cnt,int &x,int &z,int &h)
{
    if(root==NULL || x==1)
    {
        return;
    }
    inorderagain(root->left,k,cnt,x,z,h);
    cnt++;
    if(x==1) return;
    if(cnt==k){
        z=root->data;
        x=1;
        return;
    }
    else if(cnt==k-1)h=root->data;
    inorderagain(root->right,k,cnt,x,z,h);
}
float findMedian(struct Node *root)
{
      //Code here
      int count=0;
      inorder(root,count);
      int k=(count/2)+1;
      int l,cnt=0;
      int x=0,z=0,h;
      inorderagain(root,k,cnt,x,z,h);
      float a=z,b=h;
      if(count%2){
          return a;
      }
      return (a+b)/2;
      
}

