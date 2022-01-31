class Solution {
public:
        
    int maximumWealth(vector<vector<int>>& accounts) {
        
           int richest = 0;
            for(auto i:accounts)
            {
                    richest=max(richest,accumulate(i.begin(),i.end(),0));
            }
            return richest;
            
    }
};