class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
            unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++)
        {
                arr[i]=arr[i]%k;
                if(arr[i]<0)arr[i]=arr[i]+k;
                mp[arr[i]]++;
        }
            for(auto it:mp)
            {
                int number=it.first;
                    int frq=it.second;
                    if(number)
                    {
                            if(number==k-number)
                            {
                                    if(frq%2==1)
                                    {
                                            return false;
                                    }
                            }
                            if(frq!=mp[k-number])
                            {
                                    return false;
                            }
                    }
            }
            return true;
    }
};