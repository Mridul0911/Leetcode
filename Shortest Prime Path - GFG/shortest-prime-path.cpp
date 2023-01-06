//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
   bool isPrime(int num)
    {
        if(num==1) return false;
        for(int i=2;i*i<=num;i++)
            if(num%i==0) return false;
        return true;
    }
    int shortestPath(int Num1,int Num2)
    {   
        queue<int> q;
        q.push(Num1);
        int cnt=0;
        unordered_set<int> mp;
        while(!q.empty())
        {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                int num=q.front();
                q.pop();
                if(num==Num2) return cnt;
                string g=to_string(num);
                for(int j=0;j<4;j++)
                {
                    for(char c='0';c<='9';c++)
                    {
                        g[j]=c;
                        int new_num=stoi(g);
                        if(new_num>=1000 && new_num<=9999 && isPrime(new_num) && mp.count(new_num) == 0) 
                        {
                            q.push(new_num);
                            mp.insert(new_num);
                        }
                    }
                    g[j]=to_string(num)[j];
                }
            }
            cnt++;
            }
        return -1;
    }
};


//{ Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    Solution obj;
    while(t--)
    {
        int Num1,Num2;
        cin>>Num1>>Num2;
        int answer=obj.shortestPath(Num1,Num2);
        cout<<answer<<endl;
    }
}
// } Driver Code Ends