#include <bits/stdc++.h>

using namespace std;

const int Mod = 1e9 + 7;

int main(){
  int n;
  cin >> n;
  vector<vector<int>> v(n);
  for(auto &xax_ : v) {
    xax_.resize(n);
    for(auto &xax : xax_)
        cin >> xax;
  }
  vector<int> dp(1 << n);
  dp[0] = 1;
  for(int msk = 0; msk < (1 << n); ++ msk){
    int per = __builtin_popcount(msk);
    for(int i = 0; i < n; i++){
      if(!((msk >> i) & 1) && v[per][i]){
        (dp[msk | (1 << i)] += dp[msk]) %= Mod;
      }
    }
  }
  cout << dp.back() << endl;
  return 0;
}