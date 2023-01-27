class Solution {
public:
        void dfs(vector<string>& words,int i,int j,unordered_map<string,int> &mp,unordered_map<string,int> &ans,int count)
        {
                if(j==words[i].size())
                {
                        if(count>1)
                        {
                                if(!ans.count(words[i]))
                                {
                                        ans[words[i]]++;
                                }
                        }
                        return;
                }
                string str="";
                for(int k=j;k<words[i].size();k++)
                {
                        str+=words[i][k];
                        if(mp.count(str))
                        {
                                dfs(words,i,k+1,mp,ans,count+1);
                        }
                }
        }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_map<string,int> mp;
        for(auto it:words)
        {
                mp[it]++;
        }
        string str="";
            unordered_map<string,int> ans;
        vector<string> a;
        for(int i=0;i<words.size();i++)
        {
                dfs(words,i,0,mp,ans,0);
        }
        for(auto it:ans)
        {
                a.push_back(it.first);
        }
        return a;
    }
};