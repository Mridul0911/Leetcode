class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
           vector<pair<pair<int,int>,int>> inp;
           vector<int> finalanswer;
           for(int i=0;i<tasks.size();i++)
           {
                        inp.push_back({{tasks[i][0],tasks[i][1]},i});
           }
           sort(inp.begin(),inp.end());
       int time=1;
            int i=0;
      while(i<inp.size())
      {
              while(i<inp.size() && time>=inp[i].first.first)
              {
                      pq.push({inp[i].first.second,inp[i].second});
                      i++;
              }
              if(pq.empty())
              {
                      finalanswer.push_back(inp[i].second);
                      time=inp[i].first.first+inp[i].first.second;
                      i++;
              }
              else
              {
              finalanswer.push_back(pq.top().second);
              time+=pq.top().first;
              pq.pop();
              }
              cout<<time<<" "<<endl;
      }
       while(pq.size()){
               cout<<pq.top().second<<endl;
            finalanswer.push_back(pq.top().second);
            pq.pop();
        }
        return finalanswer;     
    }
};