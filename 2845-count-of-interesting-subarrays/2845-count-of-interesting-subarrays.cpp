class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long count = 0;
        int prefix = 0;    
        unordered_map<int, long long> mp;
        mp[0] = 1;
        for(auto &it:nums){
            prefix=(prefix+(it%modulo==k))%modulo;
            if (mp.find((prefix-k+modulo)%modulo)!=mp.end()){
                count+=mp[(prefix-k+modulo)%modulo];
            }
            mp[prefix]++;
        }
        return count;    
    }
};