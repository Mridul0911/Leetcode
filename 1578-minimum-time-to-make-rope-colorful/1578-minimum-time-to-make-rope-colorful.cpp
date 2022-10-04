class Solution {
public:
    int minCost(string s, vector<int>& cost) 
    {
        ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
        int ans=0;
        int sum=0;
        int j=1;
        int i=0;
        int mincost=0;
      while(j<s.length())
      {
        if(s[i]==s[j])
        {
          if(cost[i]<=cost[j])
          {
                    mincost+=cost[i];
                    i=j;
                    j++;
         }
         else if(cost[i]>cost[j])
         {
                    mincost+=cost[j];
                    j++;
         }
        }
          else
          {
              i=j;
              j++;
          }
      
          
      }
    
    
    return mincost;
    }
};