#include <bits/stdc++.h>

using namespace std;


int main(){
  int n;
  cin >> n;
  int dp[n][n];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      char c;
      cin >> c;
      if(c == '1'){
        dp[i][j] = 1;
      }
      else dp[i][j] = 1e6;
      if(i == j) dp[i][j] = 0;
    }
  }
  int m; cin >> m;
  vector < int > p(m);
  for(int i = 0; i < m; i++){
    cin >> p[i];
    p[i]--;
  }
  for(int k = 0; k < n; k++){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }
  vector < int > res;
  res.push_back(0);
  int lst = 0;
  for(int i = 1; i < m; i++){
    int fix = i - lst;
    int dist = dp[p[lst]][p[i]];
    if(dist <  fix){
      res.push_back(i - 1);
      lst = i - 1;
    }
  }
  res.push_back(m - 1);
  cout << (int)res.size() << endl;
  for(int i : res){
    cout << p[i] + 1 << " ";
  }
  return 0;
}
  
      
    
  
  
  
  
  
  
  
