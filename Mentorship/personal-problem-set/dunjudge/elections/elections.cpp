#include <bits/stdc++.h>

using namespace std;

const int N = 300000 + 10;
int dp[N][2], n, k, pre[N];
string s;

int solve(int i, int j){
  if(i == n){
    return 0;
  }

  int a = solve(i + 1, 0);
  int b = solve(i + k, 1);
}

int main(){
  cin >> n >> k >> s;
  memset(dp, -1, sizeof dp);
  for(auto i = 0; i < n; ++ i){
    pre[i + 1] = (s[i] == 'J' ? 1 : -1);
  }
  for(auto i = 1; i < n + 1; ++ i){
    pre[i] += pre[i - 1];
  }
  int ans = max(solve(0, 0), solve(0, 1));
  cout << ans;
  return 0;
}