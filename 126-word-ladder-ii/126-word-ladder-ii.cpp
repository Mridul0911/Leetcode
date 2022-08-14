class Solution {
    vector<vector<string>>ans;
    void dfs(string s,string e,unordered_map<string,unordered_set<string>>&g,vector<string>path){
        if(s==e){
            path.push_back(s);
            reverse(path.begin(),path.end());
            ans.push_back(path);
            return;
        }
        for(auto it:g[e]){
            path.push_back(e);
            dfs(s,it,g,path);
            path.pop_back();
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,bool>dict;
        for(auto it:wordList){
            dict[it]=true;
        }
        unordered_map<string,unordered_set<string>>g;
        queue<string>q;
        unordered_map<string,int>vis;
        q.push(beginWord);
        vis[beginWord]=0;
        
        while(q.size()){
            string curr=q.front();
            q.pop();
            
            for(int i=0;i<curr.size();i++){
                string temp=curr;
                for(char c='a';c<='z';c++){
                    if(curr[i]==c)
                        continue;
                    else{
                        temp[i]=c;
                        if(dict.count(temp)>0){
                            if(vis[temp]==0 || vis[temp]>vis[curr]+1){
                                vis[temp]=vis[curr]+1;
                                q.push(temp);
                                g[temp].clear();
                                g[temp].insert(curr);
                            }
                            else if(vis[temp]==vis[curr]+1){
                                g[temp].insert(curr);
                            }
                        }
                    }
                }
            }
        }
        // vector<string>path={beginWord};
        // dfs(beginWord,path,g,endWord);
        if(vis.count(endWord)==0)
            return ans;
         vector<string>path;
        dfs(beginWord,endWord,g,path);
        return ans;
    }
};










