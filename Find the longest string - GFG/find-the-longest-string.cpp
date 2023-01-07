//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    static bool cmp(string s1,string s2)
    {
        if(s1.length()!=s2.length())
        {
            return s1.length()<s2.length();
        }
        return s1>s2;
    }
    string longestString(vector<string> &words)
    {
        // code here
        unordered_map<string,int> mp;
        for(int i=0;i<words.size();i++)
        {
            mp[words[i]]++;
        }
        sort(words.begin(),words.end(),cmp);
        string ans1="";
        for(int i=words.size()-1;i>=0;i--)
        {
            string g=words[i];
            string h="";
            int ans=true;
            for(int j=0;j<g.size();j++)
            {
                h+=g[j];
                if(mp[h]==0)
                {
                    ans=false;
                    break;
                }
            }
            if(ans)
            {
                return g;
            }
        }
        return "";
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends