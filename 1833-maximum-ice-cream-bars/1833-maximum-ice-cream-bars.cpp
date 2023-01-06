class Solution {
public:         
    int maxIceCream(vector<int>& costs, int coins) {
            sort(costs.begin(),costs.end());
            int ans=0;
            long long int f=coins;
            for(int i=0;i<costs.size();i++)
            {    
                    f=f-costs[i];
                    if(f>=0)
                    {
                            ans++;
                    }
            }   
            return ans;
    }          
};            