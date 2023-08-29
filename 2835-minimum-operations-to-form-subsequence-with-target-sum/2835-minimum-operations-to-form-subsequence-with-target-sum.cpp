class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
      long long int sum=0;
       for(auto it:nums) 
       {
           sum+=it;
       }
        if(target>sum)
        {
            return -1;
        }
        sort(nums.begin(),nums.end());
        int ans=0;
       while(target>0)
       {
            int a=nums.back();
           nums.pop_back();
           if(sum-a>=target)
           {
               sum-=a;
           }
           else if(a<=target)
           {
               sum-=a;
               target-=a;
           }
           else
           {
               nums.push_back(a/2);
               nums.push_back(a/2);
               ans++;
           }
       }
        return ans;
    }
};