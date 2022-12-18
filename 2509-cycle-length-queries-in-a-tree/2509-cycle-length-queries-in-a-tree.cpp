class Solution {
public:
    int f(int x,int y)
    {
        
       if(x==y)
       {
           return 1;
       }
        if(x>y)
        {
            return 1+f(x/2,y);
        }
        return 1+f(x,y/2);
    }
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& q) {
        vector<int>ans(q.size());
        for(int i=0;i<q.size();i++)
        {
            int u=q[i][0];
            int v=q[i][1];
            ans[i]=f(u,v);
        }
        return ans;
    }
};