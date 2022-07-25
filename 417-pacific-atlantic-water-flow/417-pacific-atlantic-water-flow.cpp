class Solution {
public:
    pair<int,int> dp[201][201];
    pair<bool,bool> dfs(vector<vector<int>>& h,int i,int j,vector<vector<int>>& visited)
    {
        if(i<0 || j<0 || i>=h.size() || j>=h[0].size())
        {
            return {false,false};
        }
        if(dp[i][j].first==1 && dp[i][j].second==1) return {true,true};
        if(visited[i][j]==1) return {false,false};
        bool a=false;
        bool pa=false;
        if((i==0 || j==0)) pa=true;
        if((i==h.size()-1 || j==h[0].size()-1)) a=true;
        visited[i][j]=1;
        if(i>0 && h[i][j]>=h[i-1][j])
        {
            auto p=dfs(h,i-1,j,visited);
            if(p.first) a=true;
            if(p.second) pa=true;
            if(a==true && pa==true){
                visited[i][j]=0;
                return dp[i][j]={true,true};
            }
        }
        if(i<h.size()-1 && h[i][j]>=h[i+1][j])
        {
            auto p=dfs(h,i+1,j,visited);
            if(p.first) a=true;
            if(p.second) pa=true;
            if(a==true && pa==true){
                visited[i][j]=0;
                return dp[i][j]={true,true};
            }
        }
        if(j>0 && h[i][j]>=h[i][j-1])
        {
            auto p=dfs(h,i,j-1,visited);
            if(p.first) a=true;
            if(p.second) pa=true;
            if(a==true && pa==true){
                visited[i][j]=0;
                return dp[i][j]={true,true};
            }
        }
        if(j<h[0].size()-1 && h[i][j]>=h[i][j+1])
        {
            auto p=dfs(h,i,j+1,visited);
            if(p.first) a=true;
            if(p.second) pa=true;
            if(a==true && pa==true){
                visited[i][j]=0;
                return dp[i][j]={true,true};
            }
        }
        visited[i][j]=0;
        return dp[i][j]={a,pa};
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        memset(dp,-1,sizeof(dp));
        vector<vector<int>> visited(heights.size(),vector<int>(heights[0].size(),0));
        for(int i=0;i<heights.size();i++)
        {
            for(int j=0;j<heights[0].size();j++)
            {
                auto p=dfs(heights,i,j,visited);
                if(p.first==true && p.second==true) ans.push_back({i,j});
            }
        }
        return ans;
        
    }
};