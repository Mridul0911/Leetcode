class Solution {
public:
   bool isAllStars(string & S1, int i) 
   {
  for (int j = 1; j <= i; j++) {
    if (S1[j - 1] != '*')
      return false;
  }
  return true;
}

bool find(string & S1, string & S2) {

  int n = S1.size();
  int m = S2.size();

  vector < bool > prev(m + 1, false);
  vector < bool > cur(m + 1, false);

  prev[0] = true;

  for (int i = 1; i <= n; i++) {
    cur[0] = isAllStars(S1, i);
    for (int j = 1; j <= m; j++) {

      if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?')
        cur[j] = prev[j - 1];

      else {
        if (S1[i - 1] == '*')
          cur[j] = prev[j] || cur[j - 1];

        else cur[j] = false;
      }
    }
    prev = cur;
  }

  return prev[m];

}
       bool isMatch(string s, string p) {
                ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
          return find(p,s);
       }
};