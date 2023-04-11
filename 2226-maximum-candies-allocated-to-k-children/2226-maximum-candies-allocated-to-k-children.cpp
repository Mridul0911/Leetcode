class Solution {
public:
    bool solve(vector<int> &candies,long long mid,long long k)
    {
        long long ans=0;
        for(int i=0;i<candies.size();i++)
        {
            ans+=(candies[i]/mid);
            if(ans>=k)
            {
                cout<<mid<<" "<<ans<<endl;
                return true;
            }
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long low=1;
        long long high=*max_element(candies.begin(),candies.end());
        long long ans=0;
        
        while(low<=high)
        {
            long long mid=low+(high-low)/2;
            // cout<<mid<<endl;
            if(solve(candies,mid,k))
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
};