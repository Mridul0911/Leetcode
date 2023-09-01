class Solution {
public:
        int findbits(int i)
        {
                int count=0;
                while(i!=0)
                {
                        if(i%2==1)
                        {
                            count++;    
                        }
                        i=i/2;
                }
                return count;
        }
    vector<int> countBits(int n) {
        vector<int> ans;
            for(int i=0;i<=n;i++)
            {
                   
                    ans.push_back(findbits(i));
            }
            return ans;
    }
};