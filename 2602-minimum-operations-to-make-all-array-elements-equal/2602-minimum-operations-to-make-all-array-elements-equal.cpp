class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        vector<long long> pre(nums.size());
            vector<long long> ans;
            sort(nums.begin(),nums.end());
              pre[0]=nums[0];
            for(int i=1;i<nums.size();i++)
            {
                    pre[i]=nums[i]+pre[i-1];
            }
            long long n=nums.size();
            for(auto it:queries)
            {
                    long long val=it;
                    long long ind=upper_bound(nums.begin(),nums.end(),val)-nums.begin();
                    if(ind==0)
                    {
                            long long ans1=abs(pre[n-1]-(val*(n)));
                            ans.push_back(ans1);
                    }
                    else
                    {
                    long long sum1=pre[n-1]-pre[ind-1];
                    long long sum2=pre[ind-1];
                    long long ans2=abs(sum1-(long long)(val*(n-ind)))+abs(sum2-(long long)(val*ind));
                    ans.push_back(ans2);
                    }
            }
            return ans;
    }
};