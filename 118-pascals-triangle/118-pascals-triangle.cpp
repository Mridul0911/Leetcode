class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> gg;
            for(int i=0;i<numRows;i++)
        {
                vector<int> ans;
                int val=1;
                for(int j=0;j<=i;j++)
                {
                        ans.push_back(val);
                        val=(val*(i-j))/(j+1);
                }
                    gg.push_back(ans);
                    ans.clear();
        }
        return gg;    
            
            
    }
};