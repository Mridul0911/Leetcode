class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
         vector<int> count1(7);
            vector<int> count2(7);
            vector<int> same(7);
            for(int i=0;i<tops.size();i++)
            {
                    count1[tops[i]]++;
                    count2[bottoms[i]]++;
                    if(tops[i]==bottoms[i])
                    {
                            same[tops[i]]++;
                    }
            }
            int n=tops.size();
            int ans=INT_MAX;
            
            for(int i=1;i<=6;i++)
            {
                    if(count1[i]+count2[i]-same[i]==n){
                           ans=min(ans,min(count1[i],count2[i])-same[i]);
                    }
            }
            if(ans==INT_MAX){
                    return -1;
            }
            return ans;
    }
};