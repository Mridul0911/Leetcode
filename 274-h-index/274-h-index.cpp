class Solution {
public:
    int hIndex(vector<int>& citations) 
    {
            int n=citations.size();
            sort(citations.begin(),citations.end(),greater<int>());
            int finalans=0;
            for(int i=0;i<n-1;i++)
            {
                    if(citations[i]>=(i+1) && (i+1)>=citations[i+1])
                    {
                            cout<<citations[i]<<"-->"<<i<<endl;
                           finalans=i+1; 
                    }
            }
            if(citations[citations.size()-1]>=n )
            {
                    finalans=n;
            }
            return finalans;
     }
};