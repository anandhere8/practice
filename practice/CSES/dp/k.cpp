#include <bits/stdc++.h>

using namespace std;

bool dp[101][100005];

int main(){
  int n; cin >> n;
  vector < int > v(n + 1);
  for(int i = 0; i < n; i++){
    cin >> v[i + 1];
  }
  dp[0][0] = 1;
  for(int i = 1; i <= n; i++){
    for(int j = 0; j <= 100000; j++){
      dp[i][j] = dp[i - 1][j];
      if(v[i] <= j){
        dp[i][j] |= dp[i - 1][j - v[i]];
      }
    }
  }
  vector < int > res;
  for(int j = 1; j <= 100000; j++){
    if(dp[n][j]){
      res.push_back(j);
    }
  }
  
  cout << (int)res.size() << endl;
  for(auto x : res) cout << x << " ";
  return 0;
}
