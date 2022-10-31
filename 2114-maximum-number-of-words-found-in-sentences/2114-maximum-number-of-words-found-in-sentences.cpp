class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
            int ans=INT_MIN;
        for(auto it:sentences)
        {
                int count=0;
                for(auto gg:it)
                {
                        if(gg==' ')
                        {
                                count++;
                        }
                }
                ans=max(ans,count+1);
        }
            return ans;
    }
};