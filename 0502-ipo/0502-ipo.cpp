class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) 
    {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > min;
        
        for(int i=0;i<profits.size();i++)
        {
            min.push({capital[i],profits[i]});
        }
        
    priority_queue<pair<int,int> > max;
        for(int i=0;i<k;i++)
        {
            while(min.size()>0 && min.top().first<=w)
            {
                pair<int,int> it=min.top();
                max.push({it.second,it.first});
                min.pop();
            }
            if(max.size()>0)
            {
                w+=max.top().first;
                max.pop();
            }
        }
        
        return w;
    }
};