class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
       int prefix=0;
        for(auto it:customers)
        {
            if(it=='Y')
            {
                prefix++;
            }
        }
       int ans=0;
        int mini=prefix;
        int cntn=0;
        for(int i=0;i<n;i++)
        {
            if(customers[i]=='Y')
            {
                prefix--;
            }
            else
            {
                cntn++;   
            }
            if(mini>prefix+cntn)
            {
                ans=i+1;
                mini=prefix+cntn;
            }
        }
        return ans;
    }
};