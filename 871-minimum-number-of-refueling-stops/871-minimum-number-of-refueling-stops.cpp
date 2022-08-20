class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
      stations.push_back({target, 0});
	priority_queue <int> q;
	int ret = 0;
	for (auto &x : stations) {
		while (startFuel < x[0] && !q.empty()) 
        { 
			startFuel += q.top(); 
            q.pop();
			ret++;
		}
		if (startFuel < x[0]) return -1;
		q.push(x[1]);
	}
	return ret;   
    }
};