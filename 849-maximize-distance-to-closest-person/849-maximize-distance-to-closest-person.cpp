class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> left(seats.size(),-1);
            int n=seats.size();
            vector<int> right(seats.size(),-1);
            if(seats[0]==1)
            {
                    left[0]=0;
            }
            else
            {
                    left[0]=-1;
            }
            if(seats[n-1]==1)
            {
                    right[n-1]=n-1;
            }
            else
            {
                    right[n-1]=-1;
            }
            for(int i=1;i<n;i++)
            {
                  if(seats[i]==1)
                  {
                          left[i]=i;
                  }
                    else
                    {
                            if(left[i-1]!=-1)
                            {
                                  left[i]=left[i-1];  
                            } 
                    }
                            
            }
            for(int i=n-2;i>=0;i--)
            {
                    if(seats[i]==1)
                    {
                            right[i]=i;
                    }
                    else
                    {
                            if(right[i+1]!=-1)
                            {
                                    right[i]=right[i+1];
                            }
                    }
            }
            int maxdis=INT_MIN;
             for(int i=0;i<n;i++)
             {
                 if(seats[i]==0)   
                 {
                         if(left[i]==-1)
                         {
                                 int x=right[i];
                                 maxdis=max(maxdis,(right[i]-i));
                         }
                         else
                         {
                         maxdis=max(maxdis,min(abs(left[i]-i),abs(right[i]-i)));
                         }
                         
                 }
                     else
                     {
                             continue;
                     }
             }
          return maxdis;  
    }
};