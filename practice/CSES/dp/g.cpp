#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, T;
  cin >> n >> T;
  int A[n + 1], W[n + 1];
  for(int i = 1; i <= n; i++) cin >> A[i];
  for(int i = 1; i <= n; i++) cin >> W[i];
  int dp[2][T + 1];
  memset(dp, 0, sizeof dp);
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= T; j++){
      auto &res = dp[i % 2][j];
      res  = dp[(i % 2) ^ 1][j];
      if(j >= A[i])
        res = max(res, W[i] + dp[(i % 2) ^ 1][j - A[i]]);
    }
  }
  cout << dp[n % 2][n];
  return 0;
}
