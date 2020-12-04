#include<bits/stdc++.h>

#define EB emplace_back

#define F first
#define S second
#define all(x) x.begin(),x.end()
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;
const int N = 501;
int dp[N][N][N], A[N], n;

const int INF = 1e9;

int solve(int i, int x, int pre){
  if(i >= n){
    return 0;
  }
  int &tmp = dp[i][x][pre];
  if(tmp != -1){
    return tmp;
  }
  tmp = 1e9;
  if(A[i] >= pre)
    tmp = min(tmp, solve(i + 1, x, A[i]));
  if(x >= pre && A[i] > x)
    tmp = min(tmp, 1 + solve(i + 1, A[i], x));
  return tmp;
}

void test_case(){
  cin >> n;
  int x; cin >> x;
  for(int i = 0; i < n; i++){
    cin >> A[i];
  }
  for(int i = 0; i <= n; i++){
    for(int j = 0; j < N; j++){
      for(int k = 0; k < N; k++)
        dp[i][j][k] = -1;
    }
  }
  int ans = solve(0, x, 0);
  if(ans == INF) 
    ans = -1;
  cout << ans;
}

int32_t main(){
  IOS;
  int tt = 1; 
  cin >> tt;
  while(tt--){
    test_case();
    cout << endl;
  }
  return 0;
}
