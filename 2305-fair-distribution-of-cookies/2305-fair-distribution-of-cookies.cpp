class Solution {
public:
        int ans=INT_MAX;
        void find(int start,vector<int> &nums,int n,int k,vector<int> &cook)
        {
                if(start==n)
                {
                       int maxm = INT_MIN;
                    for(int i=0;i<k;i++){
                        maxm = max(maxm,cook[i]);
                    }
                    ans = min(ans,maxm);
                    return;
                }
                for(int i=0;i<k;i++)
                {
                        cook[i]+=nums[start];
                        find(start+1,nums,n,k,cook);
                        cook[i]-=nums[start];
                }
        }
    int distributeCookies(vector<int>& cookies, int k) {
        int n=cookies.size();
            vector<int> cook(k,0);
            find(0,cookies,n,k,cook);
           return ans; 
    }
};