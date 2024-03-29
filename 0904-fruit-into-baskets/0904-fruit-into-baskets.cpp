class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int num=2;
            int i=0;
            int j=0;
            unordered_map<int,int> mp;
            int maxi=0;
            int n=fruits.size();
            while(j<n)
            {
                    mp[fruits[j]]++;
                    while(mp.size()>num)
                    {
                                 mp[fruits[i]]--;
                                 if(mp[fruits[i]]==0)
                                 {
                                         mp.erase(fruits[i]);
                                 }
                                 i++;
                    }
                    maxi=max(maxi,j-i+1);  
                    j++;
            }
            return maxi;
    }
};