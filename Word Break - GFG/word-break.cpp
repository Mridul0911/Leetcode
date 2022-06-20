// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings
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
        }
        node->setEnd();
    }
     bool search(string word) {
        Node *node=root;
            for(int i=0;i<word.size();i++)
            {
                    if(!node->containsKey(word[i]))
                    {
                            return false;
                    }
                    node=node->get(word[i]);
            }
            return node->isEnd();
    }
    bool wordBreak(string str)
    {
        int size = str.size();
     
        if (size == 0)
            return true;
     
        for (int i = 1; i <= size; i++) {
            if (search(str.substr(0, i)) && wordBreak(str.substr(i, size - i)))
                return true;
        }
        return false;
    }

};

class Solution
{
public:
    int wordBreak(string A, vector<string> &B) {
        //code here
        Trie *trie;
        trie=new Trie();
        for(auto it:B)
        {
            trie->insert(it);
        }
        bool g=trie->wordBreak(A);
        return g;
            
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends