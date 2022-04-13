class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
       vector<vector<int>> ans(n,vector<int> (n));
          int i=0;
            int j=0;
            int p=1;
            int r=n;
            int c=n;
           while(i<r && j<c)
           {
                   for(int k=j;k<r;k++)
                   {
                           ans[i][k]=p++;
                   }
                   i++;
                   for(int k=i;k<c;k++)
                   {
                           ans[k][c-1]=p++;
                   }
                   c--;
                   if(j<c)
                   {
                           for(int k=c-1;k>=j;k--)
                           {
                                   ans[r-1][k]=p++;
                           }
                           r--;
                   }
                   if(i<r)
                   {
                         for(int k=r-1;k>=i;k--) ans[k][j]=p++;
                            j++;
                   }
            }
            return ans;
            
    }
};