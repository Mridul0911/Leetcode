class Solution {
public:
    bool flag[100011];
    vector<int> graph[100001], pos;
    vector<char> st;
    string str;
          void dfs(int nd){
        flag[nd] = true;
        st.push_back(str[nd]);
        pos.push_back(nd);
        
        for(auto v: graph[nd]){
            if(!flag[v]){
                dfs(v);
            }
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = pairs.size();
        for(int i=0;i<n;i++)flag[i] = false;
        str = s;
        for(int i=0;i<n;i++){
            int u = pairs[i][0];
            int v = pairs[i][1];
            
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        for(int i=0;i<n;i++){
            if(!flag[i]){
                pos.clear();
                st.clear();
                dfs(i);
                
                sort(st.begin(), st.end());
                sort(pos.begin(), pos.end());
                
                for(int j=0;j<pos.size();j++){
                    str[ pos[j] ] = st[j];
                }
            }
        }
        
        return str;
    }
   };