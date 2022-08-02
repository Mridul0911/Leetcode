class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target){
        unordered_map<int,vector<int>> mp;
        for (int i = 0; i < routes.size(); i++) 
        {
            for (auto n : routes[i])
            {
                    mp[n].push_back(i);
            }
        }
            queue<int> q;
            q.push(source);
            int ans=0;
            set<int> visitedStop;
            set<int> visitedBus;
            while(!q.empty())
            {
                    int size=q.size();
                    set<int> tmp;
                    while(size--)
                    {
                        int gg=q.front();
                            q.pop();
                            if(gg==target)
                            {
                                    return ans;
                            }
                            if (visitedStop.count(gg)) continue;
                            visitedStop.insert(gg);
                            for(auto it:mp[gg])
                            {
                               if (visitedBus.count(it)) continue;
                                visitedBus.insert(it);     
                                    for(auto hh:routes[it])
                                    {
                                           tmp.insert(hh);
                                    }
                            }
                    }
                    for(auto it:tmp)
                    {
                            q.push(it);
                    }
                    ans++;
            }
            return -1;
    }
};  