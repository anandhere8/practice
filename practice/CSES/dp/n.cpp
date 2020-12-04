#include<bits/stdc++.h>

#define EB emplace_back
#define int long long
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

void test_case(){
  int n;
  cin >> n;
  int A[n];
  for(int i = 0; i < n; i++){
    cin >> A[i];
  }
  const int INF = 1e9;
  vector < int > dp(n + 1, INF);
  dp[0] = -INF;
  for(int i = 0; i < n; i++){
    int j = lower_bound(all(dp), A[i]) - dp.begin();
    if(dp[j - 1] < A[i] && A[i] < dp[j]){
      dp[j] = A[i];
    }
  }
  int res = 0;
  for(int i = 0; i <= n; i++){
    if(dp[i] < INF){
      res = i;
    }
  }
  cout << res;
}

int32_t main(){
	IOS;
	int tt = 1; 
  //cin >> tt;
	while(tt--){
    test_case();
  }
	return 0;
}
