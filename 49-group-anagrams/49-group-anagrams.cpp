class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    
        map<string,vector<string>> m;
        for(int i=0;i<strs.size();i++)
        {
            string ans=strs[i];
            sort(ans.begin(),ans.end());
            m[ans].push_back(strs[i]);
        }
        vector<vector<string>> use;
        for(auto i:m)
        {
            use.push_back(i.second);
        }
        return use;
        
        
        
        
    }
};