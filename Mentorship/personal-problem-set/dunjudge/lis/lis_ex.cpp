#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10, INF = 1e12 + 10;

int main(){
  int n; cin >> n;
  int A[n];
  for(int i = 0; i < n; i++){
    cin >> A[i];
  }
  vector < int > dp(n + 1, INF);
  int res = 0;
  dp[0] = -INF;
  for(int i = 0; i < n; i++){
    int j = upper_bound(dp.begin(), dp.end(), A[i]) - dp.begin();
    if(dp[j - 1] < A[i] && A[i] < dp[j]){
      dp[j] = A[i];
    }
  }  
  for(int i = 0; i <= n; i++){
    if(dp[i] < INF){
      res = i;
    }
  }
  cout << res;
  return 0;
}
