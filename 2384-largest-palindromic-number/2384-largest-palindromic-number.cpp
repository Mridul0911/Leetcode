class Solution {
public:
    string largestPalindromic(string num) {
        map<char,int> mp;
            for(auto it:num)
            {
                    mp[it]++;
            }
            vector<pair<int,int>> even;
            vector<pair<int,int>> odd;
            for(auto it:mp)
            {
                    if(it.second%2==0)
                    {
                            even.push_back({it.first,it.second});
                    }
                    else
                    {
                            if(it.second>2)
                            {
                                 even.push_back({it.first,it.second-1});
                                 odd.push_back({it.first,1});
                            }
                            else
                            {
                                    odd.push_back({it.first,it.second});
                            }
                    }
            }
           string ans="";
        if(odd.size()) ans +=odd.back().first;
        if(even.size()==1 && even.back().first=='0') return ans!=""?ans:"0";
        for(auto [character,freq]: even)
            ans = string(freq/2,character) + ans + string(freq/2,character);
        return ans;
    }
};