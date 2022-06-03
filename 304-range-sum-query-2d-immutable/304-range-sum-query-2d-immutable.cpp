class NumMatrix {
public:
       vector<vector<int>> ans;
    NumMatrix(vector<vector<int>>& matrix) {
                int n=matrix.size();
            int m=matrix[0].size();
             ans = vector<vector<int>>(n+1,vector<int>(m+1,0));
            for(int i=0;i<n;i++)
            {
                    for(int j=0;j<m;j++)
                    {
                      ans[i+1][j+1]=ans[i+1][j]+ans[i][j+1]+matrix[i][j]-ans[i][j];
                            //cout<<ans[i][j]<<" ";
                    }
                    cout<<endl;
            }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
    return ans[row2 + 1][col2 + 1] - ans[row1][col2 + 1] - ans[row2 + 1][col1] + ans[row1][col1];
    }
};
