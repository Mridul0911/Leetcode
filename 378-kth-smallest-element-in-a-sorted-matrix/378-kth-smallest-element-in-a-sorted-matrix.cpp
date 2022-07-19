class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
         priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>> > pq;
        int n=matrix.size();
        for(int i=0; i<n; ++i)
        {
  //              cout<<matrix[0][i]<<" ";
            pq.push({matrix[0][i],{0,i}});
        }
         int ans;
        while(k--)
        {
            int val=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            ans=val;
            if(row!=n-1)
            {
                pq.push({matrix[row+1][col],{row+1,col}});
            }
        }
        return ans;   
    }
};