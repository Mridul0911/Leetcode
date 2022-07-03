class Solution {
public:
        int binary(int x,vector<int> &potions,long long success)
        {
                int n=potions.size();
               int low=0,high=n-1;
                int idx=n;
                while(low<=high) {
                 int mid=low+(high-low)/2;
                 long long prod=(long long)x*potions[mid];
                 if(prod>=success) {
                        idx=mid;
                        high=mid-1;
                 }
                 else low=mid+1;
        }
        return n-idx;
        }
vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
            int n=spells.size();
        vector<int> ans(n,0);
            sort(potions.begin(),potions.end());
            for(int i=0;i<spells.size();i++)
            {
                    ans[i]=binary(spells[i],potions,success);
            }
            return ans;
            
            
            
            
    }
};