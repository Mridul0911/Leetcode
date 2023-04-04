class Solution {
public:
    int isPossible(int days,vector<int> bm,int m,int k)
    {
        int ans=0;
        for(int i=0;i<bm.size();i++)
        {
            if(bm[i]<=days)
            {
                int count=0;
                int j;
                for(j=i;j<bm.size() && bm[j]<=days;j++)
                {
                    count++;
                }
                if(count>=k)
                {
                    ans++;
                    if(ans==m)
                    {
                        return true;
                    }
                    j=j-(count-k);
                }
                j--;
                i=j;
            }
        }
        return false;
    }
    int minDays(vector<int>& bm, int m, int k) {
        int low=0;
        int high=*max_element(bm.begin(),bm.end());
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)>>1;
            if(isPossible(mid,bm,m,k))
            {
                ans=mid;
                high=mid-1;             
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};