class Solution {
public:
    string longestWord(vector<string>& words) {
       set<string> st;
            string res="";
            for(auto it:words)
            {
                    st.insert(it);
            }
            for(int i=0;i<words.size();i++)
            {
                    string str=words[i];
                    int n=str.size();
                    int f=0;
                    while(n-1>0)
                    {
                            string gg=str.substr(0,n-1);
                            if(st.find(gg)==st.end())
                            {
                                    f=1;
                                    break;
                            }
                            n--;
                    }
                    if(f==0 && str.size()>=res.size())
                    {
                            if(str.size()==res.size())
                            {
                                 if(res>str)   
                                 {
                                         res=str;
                                 }
                                    
                            }
                            else
                            {
                                    res=str;
                            }
                    }
            }
            return res;
    }
};