class Solution {
public:
        
    int findSmallestInteger(vector<int>& nums, int value) {
       vector<int> count(value, 0);
        for (int& a : nums)
            count[(a%value+value)%value]++;
        int stop=0;
        for (int i=0;i<value;++i)
            if (count[i]<count[stop])
                stop=i;
        return value*count[stop]+stop;
    }
};