class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
            int flag=0;
            for(auto it:wordList)
            {
                    if(it==endWord)
                    {
                            flag=1;
                    }
            }
            
            if(!flag)
            {
                    return 0;
            }
            
            queue<string> q;
            q.push(beginWord);
            set<string> st;
            for(auto it:wordList)
            {
                    st.insert(it);
            }
            int ans=0;
            while(!q.empty())
            {
                    int n=q.size();
                    ans++;
                    while(n--)
                    {
                            string s=q.front();
                            q.pop();
                            for(int i=0;i<s.size();i++) 
                            {
                                    string temp=s;
                                    for(char c='a';c<='z';c++)
                                    {
                                            temp[i]=c;
                                            if(temp==s) continue;
                                            if(temp==endWord)
                                            {
                                                    return ++ans;
                                            }
                                            if(st.find(temp)!=st.end())
                                            {
             //                                       cout<<temp<<endl;
                                                    q.push(temp);
                                                    st.erase(temp);
                                            }
                                    }
                            }
                           
                    }
            }
            return 0;
            
            
            
            
    }
};