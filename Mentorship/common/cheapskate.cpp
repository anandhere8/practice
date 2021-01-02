#include <bits/stdc++.h>

using namespace std;

template<class T, class U> T &cmax(T &x, const U &y){ return x = max<T>(x, y); }

int n;
vector<array<int, 3>> A;
long long dp[140][140][140];
int solve(int i, int m, int r){
  if(i == n){
    return 0;
  }
  auto &res = dp[i][m][r];
  if(res != -1){
    return res;
  }

  long long a = solve(i + 1, m, r);
  res = a;
  if(A[i][0] <= m){
    cmax(res, 1 + solve(i + 1, m - A[i][0], r));
  }
  if(A[i][1] <= m && A[i][2] <= r){
    cmax(res, 1 + solve(i + 1, m - A[i][1], r - A[i][2]));
  }
  return res;
}

int main(){
  memset(dp, -1, sizeof(dp));
  int m, r;
  cin >> n >> m >> r;
  A.resize(n);
  for(auto i = 0; i < n; ++ i){
    for(auto j = 0; j < 3; ++ j){
      cin >> A[i][j];
    }
  }
  //int ans = solve(0, m, r);
  // cout << ans;
  sort(A.begin(), A.end());
  int sum = 0, res = 0;
  for(auto i = 0; i < n; ++ i){
    if(sum + A[i][0] > m){
      break;
    }
    ++ res, sum += A[i][0];
  }
  cout << res;
  return 0;
}