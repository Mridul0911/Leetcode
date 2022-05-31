class Solution {
public:
    bool hasAllCodes(string s, int k) {
           set<string> ans;
        ans.insert(s.substr(0, k));
            for(int i=k;i<s.size();i++)
            {
                    string gg=s.substr(i-k+1,k);
                    //cout<<gg<<endl;
                    ans.insert(gg);
            }
            return ans.size()==pow(2,k);
    }
};