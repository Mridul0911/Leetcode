class Solution {
public:
    string removeDuplicates(string s) {
       
            string ans="";
            for(auto i:s)
            {
                    if(ans.size() && i==ans.back())
                    {
                            ans.pop_back();
                    }
                    else
                    {
                            ans.push_back(i);
                    }
            }
            return ans;
            
    }
};