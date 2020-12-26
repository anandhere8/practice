#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
  int n;
  cin >> n;
  vector<array<int, 2>> v(n);
  for(auto i = 0; i < n; ++ i){
    cin >> v[i][0] >> v[i][1];
  }
  
  vector<int> dp(1 << n, 1e16);
  dp[0] = 0;
  vector<int> pre(1 << n, 0); 
  for(int msk = 0; msk < (1 << n); ++ msk){
    int a = 0, b = 0;
    for(int i = 0; i < n; ++ i){
      if((msk >> i) & 1){
        a = max(a, v[i][0]);
        b = max(b, v[i][1]);
      }
    }
    pre[msk] = a * b;
  }
  for(auto msk = 0; msk < (1 << n); ++ msk){
    for(auto sub = msk; sub ; sub = (sub - 1) & msk){
      dp[msk] = min(dp[msk], dp[msk ^ sub] + pre[sub]);
    }
  }
  
  cout << dp.back();
  return 0;
}