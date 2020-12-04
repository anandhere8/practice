#include<bits/stdc++.h>

using namespace std; 

int main(){
  int n, T; cin >> n >> T;
  vector < int > A(n);
  for(int i = 0; i < n; i++)
    cin >> A[i];
  int INF = 1e9 + 23;
  vector < int > dp(T + 1, INF);
  dp[0] = 0;
  for(int i = 0; i <= T; i++){
    for(int x : A){
      if(x <= i){
        dp[i] = min(1 + dp[i - x], dp[i]);
      }
    }
  }
  if(dp[T] >= INF) dp[T] = -1;
  cout << dp[T];
  return 0;
}
