class Solution {
public:
        int n;
        int find(int i,int j,int left_sum,vector<int> &prefix)
        {
             int ans = -1;
             while(i<=j) 
             {
                int mid=i+(j-i)/2;
                if(prefix[mid]-left_sum>=left_sum) 
                { 
                     ans=mid;
                     j=mid-1; 
                } 
                else 
                {
                      i=mid+1;
                }
             }
             return ans;   
        }
        int find1(vector<int> &prefix,int left,int i,int right)
        {
             int ans=-1;
             while(left<=right) 
             {
                int mid=left+(right-left)/2;
                if((prefix[mid]-prefix[i])<=(prefix[n-1]-prefix[mid])) 
                {
                        ans=mid;
                        left=mid + 1;
                } 
                else
                {
                        right=mid-1;
                }
              }
              return ans;   
        }
    int waysToSplit(vector<int>& nums) {
            n=nums.size();
            int mod=1e9+7;
            vector<int> prefix(nums.size());
            prefix[0]=nums[0];
            for(int i=1;i<nums.size();i++)
            {
                    prefix[i]=prefix[i-1]+nums[i];
            }
            int ans=0;
            for(int i=0;i<nums.size()-2;i++)
            {
                int start=find(i+1,n-1,prefix[i],prefix);
                int end=find1(prefix,start,i,n-2);
                if(start!=-1 && end!=-1 && start<=end) 
                {
                        ans=(ans%mod+(end-start+1)%mod)%mod;      
                }
            }
            return ans;
    }
};