#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int n, k;
int J[N], G[N];
string s;

//int solve(int i){
  //if(i > n) return 0;
  //int a = solve(i + 1);
  //int b = 0;
  //if(i){
    //b = solve(i + k + 1) + ((J[i] > J[j]) ? 1 : -1);
  //}
  //return max(a, b);
//}

int main(){
  cin >> n >> k >> s;
  for(int i = 0; i < n; i++){
    if(s[i] == 'J') J[i + 1] = 1;
    else J[i + 1] = -1;
  }
  for(int i = 1; i <= n; i++){
    J[i] += J[i - 1];
  }
  
  int dp[n + 1][2];
  memset(dp, 0, sizeof dp);
  for(int i = 1; i <= n; i++){
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
    if(i + k <= n && i >= k){
      dp[i][1] = max(dp[i - k][0], dp[i - k][1]) + (J[i] > J[i - k - 1] ? 1 : - 1);
    }
  }
  cout << max(dp[n][0], dp[n][1]);
  return 0;
}
