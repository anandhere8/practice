#include <bits/stdc++.h>

using namespace std;

int main(){
  string s, t; cin >> s >> t;
  int n, m;
  n = s.size(), m = t.size();
  int dp[n + 1][m + 1];
  memset(dp, 0x3f, sizeof dp);
  dp[0][0] = 0;
  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= m; j++){
      if(i)
        dp[i][j] = min(dp[i][j], 1 + dp[i - 1][j]);
      if(j)
        dp[i][j] = min(dp[i][j], 1 + dp[i][j - 1]);
      if(i && j)  
        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (s[i - 1] != t[j - 1]));
    }
  }
  cout << dp[n][m];
  return 0;
}
