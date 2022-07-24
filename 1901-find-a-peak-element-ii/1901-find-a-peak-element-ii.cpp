class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        for(int i=0;i<m;i++) 
        {
            for(int j=0;j<n;j++) 
            {
                bool b = true;
                if(i>0) 
                {
                    if(mat[i][j]<mat[i-1][j]) b = false;
                }
                if(i<m-1) 
                {
                    if (mat[i][j]<mat[i+1][j]) b = false;
                }
                if(j>0) 
                {
                    if (mat[i][j]<mat[i][j-1]) b = false;
                }
                if(j<n-1) 
                {
                    if (mat[i][j]<mat[i][j+1]) b = false;
                }
                if(b) 
                {
                    return {i,j};
                }
            }
        }
        return {-1,-1};
    }
};