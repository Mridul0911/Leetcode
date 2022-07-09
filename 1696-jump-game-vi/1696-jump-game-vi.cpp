class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
         deque<int> dq;
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dq.push_front(0);
        for(int i = 1; i < n; i++) {
            while(dq.size() > 0 && i - dq.front() > k) {
                dq.pop_front();
            }
            dp[i] = nums[i];
            if(dq.size() > 0) {
                dp[i] += dp[dq.front()];
            }
            while(dq.size() > 0 && dp[i] > dp[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return dp[n-1];
    }
};