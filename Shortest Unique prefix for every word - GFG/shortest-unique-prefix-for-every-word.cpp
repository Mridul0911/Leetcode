// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
struct Node{
  Node *links[26];
  int freq;
  bool flag;
  
  bool containsKey(char ch){
      return links[ch-'a'];
  }
  Node *get(char ch)
  {
      return links[ch-'a'];
  }
  void put(char ch,Node *node)
  {
      links[ch-'a']=node;
  }
  void increaseFreq()
  {
      freq++;
  }
  int getFreq()
  {
      return freq;
  }
  void setEnd()
    {
        flag=true;
    }
    bool isEnd()
    {
        return flag;
    }
  
};
class Trie{
    private :Node *root;
    public:
    Trie()
    {
        root=new Node();
    }
    void insert(string word)
    {
        Node *node=root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
            node->freq++;
        }
        node->setEnd();
    }
    void search(string word,vector<string> &ans)
    {
        Node *node=root;
        string flag="";
        for(int i=0;i<word.length();i++)
        {
                 flag+=word[i];
                 node=node->get(word[i]);
                if(node->getFreq()==1)
                {
                       break;
                }
        }
        ans.push_back(flag);
    }
};


class Solution
{
    public:
    vector<string> findPrefixes(string arr[], int n)
    {
        
        //code here
        Trie *trie;
        trie=new Trie();
        for(int i=0;i<n;i++)
        {
            trie->insert(arr[i]);
        }
        vector<string> ans;
        for(int i=0;i<n;i++)
        {
            trie->search(arr[i],ans);
            
        }
        return ans;
    }
    
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";


        cout << "\n";

    }

    return 0;
}
  // } Driver Code Ends