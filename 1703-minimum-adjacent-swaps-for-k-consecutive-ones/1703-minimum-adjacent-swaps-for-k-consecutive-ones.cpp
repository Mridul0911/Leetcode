#define ll long long
class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        vector<int> one_ind;
            for(int i=0;i<nums.size();i++)
            {
                    if(nums[i])
                    {
                            one_ind.push_back(i);
                    }
            }
            vector<ll> prefix;
            ll sum=0;
            for(int x:one_ind)
            {
                    cout<<x<<" ";
                sum+=x;
                prefix.push_back(sum);
            }
            cout<<endl;
            ll i=0;
            ll j=k-1;
            ll finalans;
            ll ans=INT_MAX;
            ll radius;
            if(k%2==0)
            {
                    radius=(k-2)/2;
            }
            else
            {
                    radius=k/2;
            }
            cout<<"RADIUS"<<" "<<radius<<endl;
            while(j<one_ind.size())
            {
                 if(k%2)   
                 {
                       int pivot=(i+j)/2;
finalans=prefix[j]-prefix[pivot]-((pivot>0?prefix[pivot-1]:0)-(i>0?prefix[i-1]:0))-radius*(radius+1);
                 }      
                 else
                 {
                       int pivot=(i+j)/2;
finalans=prefix[j]-prefix[pivot]-((pivot>0?prefix[pivot-1]:0)-(i>0?prefix[i-1]:0))-one_ind[pivot]-radius*(radius+1)-(radius+1);
                 }
                    cout<<finalans<<endl;
              ans=min(ans,finalans);
                    i++;
                    j++;
            }
            return ans;
    }
};