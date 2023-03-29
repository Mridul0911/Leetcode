class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>> inp;
        for(int i=0;i<nums.size();i++)
        {
            for(auto it:nums[i])
            {
                inp.push_back({it,i});
            }
        }
        sort(inp.begin(),inp.end());
        int i=0;
        int j=0;
        unordered_map<int, int> count;
        int n=nums.size();
        vector<int> ans;
        int x=0;
        while(j<inp.size())
        {
            count[inp[j].second]++;
            // if(count[inp[j].second]==1)x++;
//             cout<<inp[j].first<<endl;
//             for(auto it:count)
//             {
//                 cout<<it.first<<" "<<it.second<<endl;
//             }
//             cout<<x;
//             cout<<"--------------------------"<<endl;
            
//             cout<<endl;
            if(count.size()==n)
            {
                while(count[inp[i].second]>1)
                {
                    count[inp[i].second]--;
                    i++;
                }
                if(ans.empty() || ((ans[1]-ans[0])>inp[j].first-inp[i].first))
                {
                    ans=vector<int>{inp[i].first,inp[j].first};
                }
            }
            j++;
        }
        return ans;
    }
};