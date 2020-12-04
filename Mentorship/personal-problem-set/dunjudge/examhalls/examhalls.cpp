//#include "examhalls.h"
#include <bits/stdc++.h>
using namespace std;

long long examhalls(int N, long long A[]) {
  
  long long sum = 0;
  int n = N;
  for(int i = 0; i < n; i++){
    sum += A[i];
  }
  long long ans = LLONG_MAX;
  bool dp[2][sum + 1];
  memset(dp, 0, sizeof dp);
  dp[0][0] = true;
  dp[1][0] = true;
  for(int i = 1; i<= n; i++){
    for(int j = 0; j <= sum; j++){
      dp[i % 2][j] = dp[(i % 2) ^ 1][j];
      if(A[i - 1] <= j){
        dp[i % 2][j] |= dp[(i % 2) ^ 1][j - A[i - 1]];
      }
      if(dp[i % 2][j]){
        long long a = j, b = sum - a;
        ans = min(ans, a * a + b * b);
      }
    }
  }
  return ans;
}


int main(){
  int n; cin >> n;
  long long A[n];
  for(int i = 0; i < n; i++){
    cin >> A[i];
  }
  cout << examhalls(n, A);
}
