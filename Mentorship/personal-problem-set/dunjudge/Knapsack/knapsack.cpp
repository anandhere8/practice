// techiehere08

#include <iostream>
#include <cstring>
using namespace std;

int main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T, n;
  cin >> T >> n;
  int A[n + 1], Cnt[n + 1], W[n + 1];
  int dp[2][T + 1];
  memset(dp, 0, sizeof dp);
  int res = 0;
  for(int i = 1; i <= n; i++){
    cin >> A[i] >> W[i] >> Cnt[i];
    Cnt[i] = min(Cnt[i], T / W[i]);
  }
  for(int i = 1; i <= n; i++){
    for(int j = res; j <= T; j++){
      dp[i %  2][j] = max(dp[i % 2][j], dp[(i % 2) ^ 1][j]);
      for(int k = 0; k <= Cnt[i] && j >= k * W[i]; k++){
        dp[i % 2][j] = max(dp[i % 2][j], A[i] * k + dp[(i % 2) ^ 1][j - k * W[i]]);
      }
      res = max(dp[i % 2][j], res);
    }
  }
  cout << res;
  return 0;
}
