class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
       unordered_map<int,vector<int>> mp;
            int m=mat.size();
            int n=mat[0].size();
            for(int i=0;i<mat.size();i++)
            {
                    for(int j=0;j<mat[i].size();j++)
                    {
                            mp[i-j].push_back(mat[i][j]);
                    } 
           }
           //  cout<<"MEE "<<endl;
           // for(auto it:mp)
           // {
           //         cout<<it.first<<" --- >>>";
           //         sort(it.second.begin(),it.second.end());
           //         for(auto gg:it.second)
           //         {
           //                 cout<<gg<<" ";
           //         }
           //         cout<<endl;
           // }
           //  cout<<"OUT "<<endl;
            for(int k=-(n-1);k<m;k++) 
          {
                   sort(mp[k].begin(),mp[k].end());
                   
          }
            
            for(int i=m-1;i>=0;i--) 
            {
                for(int j=n-1;j>=0;j--) 
                {
                        mat[i][j]=mp[i-j].back();
                        mp[i-j].pop_back();
                }
            }
             return mat;
    }
};