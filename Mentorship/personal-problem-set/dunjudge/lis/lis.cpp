#include <bits/stdc++.h>

using namespace std;

int main(){
  int n; cin >> n;
  int A[n + 1];
  for(int i = 1; i <= n; i++){
    cin >> A[i];
  }
  int dp[n + 1];
  fill(dp, dp + n + 1, 1);
  int res = 1;
  for(int i = 1; i <= n; i++){
    for(int j = i + 1; j <= n; j++){
      if(A[j] > A[i]){
        dp[j] = max(dp[j], 1 + dp[i]);
      }
    }
    res = max(res, dp[i]);
  }
  cout << res;
  return 0;
}
