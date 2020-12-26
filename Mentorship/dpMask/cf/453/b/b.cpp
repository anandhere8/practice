#include<bits/stdc++.h>
// #define int long long
using namespace std;

vector<pair<long long, int>> factorize(long long x){
  vector<pair<long long, int>> res;
  for(long long p = 2; p * p <= x; ++ p) if(x % p == 0){
    res.push_back({p, 0});
    while(x % p == 0) ++ res.back().second, x /= p;
  }
  if(x > 1) res.push_back({x, 1});
  return res;
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int tt = 1; 
  // cin >> tt;
  
  auto test_case = [&](){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++){
      cin >> A[i];
    }
    vector<vector<pair<long long, int>>> Fact(60);
    for(auto i = 1; i < 60; ++ i){
      Fact[i] = factorize(i);
    }
    int dp[n][61];
    memset(dp, -1, sizeof(dp));
    function<int(int, long long)> solve = [&](int i, long long msk){
      if(i >= n){
        return 0;
      }
      int res = dp[i][msk];
      if(res != -1){
        return res;
      }
      int M = 8;
      for(long long ii = 0; ii < M; ++ ii){
        int j = ii;
        if(!((msk >> ii) & 1)){
          long long tmp = msk;
          auto fac = Fact[j];
          for(auto x : fac){
            int p = x.first;
            int num = p;
            while(num < M){
              tmp |= (1ll << num);
              num += p;
            }
          }
          res = min(res, abs(A[i] - j) + solve(i + 1, tmp));
        }
      }
      return dp[i][msk] = res;
    };

    int ans = solve(0, 0);
    cout << ans << endl;
  };
  while(tt--){
    test_case();
    cout << endl;
  }
  return 0;
}
