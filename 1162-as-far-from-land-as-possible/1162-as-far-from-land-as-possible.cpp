class Solution {
public:
   void dfs(vector<vector<int>>& g, int i, int j, int dist = 1) {
  if (i < 0 || j < 0 || i >= g.size() || j >= g[i].size() || (g[i][j] != 0 && g[i][j] <= dist)) return;
  g[i][j] = dist;
  dfs(g, i - 1, j, dist + 1), dfs(g, i + 1, j, dist + 1), dfs(g, i, j - 1, dist + 1), dfs(g, i, j + 1, dist + 1);
}
int maxDistance(vector<vector<int>>& g, int steps = 0) {
  queue<pair<int, int>> q, q1;
  for (auto i = 0; i < g.size(); ++i)
    for (auto j = 0; j < g[i].size(); ++j)
      if (g[i][j] == 1)
        q.push({ i - 1, j }), q.push({ i + 1, j }), q.push({ i, j - 1 }), q.push({ i, j + 1 });
  while (!q.empty()) {
    ++steps;
    while (!q.empty()) {
      int i = q.front().first, j = q.front().second;
      q.pop();
      if (i >= 0 && j >= 0 && i < g.size() && j < g[i].size() && g[i][j] == 0) {
        g[i][j] = steps;
        q1.push({ i - 1, j }), q1.push({ i + 1, j }), q1.push({ i, j - 1 }), q1.push({ i, j + 1 });
      }
    }
    swap(q1, q);
  }
  return steps == 1 ? -1 : steps - 1;
}
};