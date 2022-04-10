class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> ans;
            for(int i=0;i<ops.size();i++)
            {
                    string s=ops[i];
                    if(ops[i]!="C" && ops[i]!="D" && ops[i]!="+")
                    {
                            int x=stoi(s);
                            ans.push_back(x);
                    }
                    else
                    {
                            if(ops[i]=="D")
                            {
                                    ans.push_back(ans[ans.size()-1]*2);
                            }
                            else if(ops[i]=="C")
                            {
                                    ans.pop_back();
                            }
                            else
                            {
                                    ans.push_back(ans[ans.size()-1]+ans[ans.size()-2]);
                            }
                    }
            }
            int finalans=0;
            for(auto it:ans)
            {
                finalans+=it;
            }
            return finalans;
            
    }
};