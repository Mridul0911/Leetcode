class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int p) {
        
        sort(tokens.begin(),tokens.end());
        int low=0;
        int high=tokens.size()-1;
        int ans=0;
        int score=0;
        while(low<=high)
        {
            if(tokens[low]<=p)
            {
                p=p-tokens[low];
                score++;
                ans=max(ans,score);
                low++;
            }
            else if(score>=1)
            {
                p+=tokens[high];
                high--;
                score--;
            }
            else
            {
                break;
            }
        }
        return ans;
        
        
        
    }
};