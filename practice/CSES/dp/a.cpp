#include<bits/stdc++.h>

using namespace std; 

int main(){
  int n; cin >> n;
  int dp[n + 10] = {};
  dp[0] = 1;
  int mod = 1e9 + 7;
  for(int i = 0; i <= n; i++){
    for(int j = 1; j <= 6; j++){
      dp[i + j] += dp[i];
      dp[i + j] %= mod;
    }
  }
  cout << dp[n];
  return 0;
}
