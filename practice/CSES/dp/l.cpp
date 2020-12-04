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
  int dp[n + 1][n + 1];
  memset(dp, 0, sizeof dp);
  for(int len = 1; len <= n; len++){
    for(int i = 0; i + len <= n; i++){
      int j = i + len;
      int a = (i <= j - 2) ? dp[i][j - 2] : 0;
      int b = (i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0;
      int c = (i + 2 <= j) ? dp[i + 2][j] :  0;
      dp[i][j] = max(A[j] + min(a, b), A[i] + min(b, c));
    }
  }
  cout << dp[0][n - 1];
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
