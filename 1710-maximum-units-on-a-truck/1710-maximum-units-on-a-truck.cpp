class Solution {
public:
        static bool cmp(vector<int> &v1,vector<int> &v2)
        {
                return v1[1]>v2[1];
        }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
          sort(boxTypes.begin(),boxTypes.end(),cmp);
            int ans=0;
            int min_required;
            for(auto it:boxTypes)
            {
                   min_required=min(truckSize,it[0]);
                    // cout<<min_required<<endl;
                    ans+=(it[1])*(min_required);
                    truckSize-=min_required;
                    cout<<truckSize<<endl;
                    if(truckSize<=0)
                    {
                            break;
                    }
            }
            return ans;        
    }
    
};