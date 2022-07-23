#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
//less_equal<int> to allow equal values in a set and less for sorting order to be increasing
typedef tree <int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        pbds s;
         vector<int>v;
         int n=nums.size();
          for(int i=n-1;i>=0;i--)
          {
                  int x=s.order_of_key(nums[i]);
                  v.push_back(x);
                  s.insert(nums[i]);
          }
            reverse(v.begin(),v.end());
            return v;
    }
};