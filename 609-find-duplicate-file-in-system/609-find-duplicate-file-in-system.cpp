class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;
        for(string s : paths)
        {
            string path="";
            int i=0;
            int n=s.size();
            while(i<n && s[i]!=' ') path+=s[i++];
            i++;
            while(i<n)
            {
                string fileName="";
                string content="";
                while(i<n && s[i]!='(') fileName+=s[i++];
                while(i<n && s[i]!=' ') content+=s[i++];
                i++; 
                mp[content].push_back(path+"/"+fileName);
            }
        }
        for(auto ele : mp)
        {
            if(ele.second.size()>1) ans.push_back(ele.second);
        }
        return ans;
    }
};