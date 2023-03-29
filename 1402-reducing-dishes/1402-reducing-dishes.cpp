class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(),s.end());
        int ind=-1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>0)
            {
                ind=i;
                break;
            }
        }
        if(ind==-1)
        {
            return 0;
        }
        int j=1;
        int sum=0;
        int ans=0;
        for(int i=ind;i<s.size();i++)
        {
            sum+=s[i];
            ans+=j*s[i];
            j++;
        }
        cout<<sum<<" "<<ans<<endl;
        int ans1=0;
        for(int i=ind-1;i>=0;i--)
        {
            ans1=ans+sum+s[i];
            if(ans1>ans)
            {
                ans=ans1;
                sum+=s[i];
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};