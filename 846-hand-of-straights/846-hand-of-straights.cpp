class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> mp;
            for(auto it:hand)
            {
                    mp[it]++;
            }    
            int n=hand.size();
            int i=0;
            while(i<n)
            {
                    auto it=mp.begin();
                    int num=it->first;
                    for(int j=0;j<groupSize;j++)
                    {
                            if(!mp.count(j+num))
                            {
                                    return false;
                            }
                            else
                            {
                                    mp[num+j]--;
                                    if(mp[num+j]==0)
                                    {
                                            mp.erase(num+j);
                                    }
                            }
                    }
                    i+=groupSize;
            }
            return true;
          }
};