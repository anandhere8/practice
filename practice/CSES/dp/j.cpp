#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int dp[N][N];

int main(){
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(i == j) continue;
      dp[i][j] = 1e9;
      for(int k = 1; k < i; k++){
        dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);
      }
      for(int k = 1; k < j; k++){
        dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
      }
    }
  }
  cout << dp[n][m];
  return 0;
}
