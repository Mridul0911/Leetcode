class Solution {
public:
        bool static cmp(pair<int,int> &p1,pair<int,int> &p2)
        {
                return (p1.first-p1.second)<(p2.first-p2.second);
        }
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
    
//                 4 4  ans+=1
//                 2 1  
//                 3 2
//                 5 4
            
            
           ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
   
            
            vector<pair<int,int>> inp;
            for(int i=0;i<capacity.size();i++)
            {
                    inp.push_back({capacity[i],rocks[i]});
            }
            sort(inp.begin(),inp.end(),cmp);
            int ans=0;
            int flag=0;
            for(auto it:inp)
            {
                    cout<<it.first<<" "<<it.second<<endl;
            }
            for(auto it:inp)
            {
                    if(it.first==it.second)
                    {
                            ans++;
                            continue;
                    }
                    else
                    {
                            if(additionalRocks<(it.first-it.second))
                            {
                                    flag=1;
                            }
                            else
                            {
                                    additionalRocks-=(it.first-it.second);
                                    ans++;
                            }
                    }
                    if(flag==1)
                    {
                            break;
                    }
                }
            return ans;
            
    }
};