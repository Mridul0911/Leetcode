//libraries required to add ordered set
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
//less_equal<int> to allow equal values in a set and less for sorting order to be increasing
typedef tree <int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        pbds s;
        int n = nums.size();
        vector<int> ans(n);
        
        for(int i=n-1; i>=0; --i)
        {
            ans[i] = s.order_of_key(nums[i]);           // logn look-up time
			s.insert(nums[i]);                //logn insertion time
        }
        
        return ans;
    }
};