#include <bits/stdc++.h>

using namespace std;

template<class T> T &ctmax(T &x, const T &y){ return x = max<T>(x, y); }

int main(){
  int n;
  cin >> n;
  int m = n;
  // cin >> m;
  int A[n][m];
  for(int i = 0; i < n; ++ i){
    for(int j = 0; j < m; ++ j){
      cin >> A[i][j];
    }
  }
  vector<long long> pre(1 << n);
  for(auto msk = 0; msk < (1 << n); ++ msk){
    for(auto i = 0; i < n; ++ i){
      if(msk & (1 << i)){
        for(auto j = i + 1; j < n; ++ j){
          if(msk & (1 << j)){
            pre[msk] += A[i][j];
          }
        }
      }
    }
  }
  
  vector<long long> dp(1 << n);
  for(auto msk = 0; msk < (1 << n); ++ msk){
    for(auto sub = msk; sub; sub = msk & (sub - 1)){
      ctmax(dp[msk], dp[msk ^ sub] + pre[sub]);
    }
  }
  cout << dp.back();
  return 0;
}