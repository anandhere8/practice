#include <bits/stdc++.h>

using namespace std;

int main(){
  int n; cin >> n;
  int INF = 1e9;
  vector < int > dp(n + 1, INF);
  dp[0] = 0;
  for(int i = 0; i <= n; i++){
    int tmp = i;
    while(tmp){
      int r = tmp % 10;
      tmp /= 10;
      if(r <= i){
        dp[i] = min(dp[i], 1 + dp[i - r]);
      }
    }
  }
  cout << dp[n];
  return 0;
}
