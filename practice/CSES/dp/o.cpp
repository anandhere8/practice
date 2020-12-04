#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
  int n;
  cin >> n;
  int s[n + 1] = {}, e[n + 1] = {}, p[n + 1] = {};
  vector < array < int, 3 >> arr(n + 1);
  for(int i = 1; i <= n; i++){
    cin >> arr[i][1] >> arr[i][0] >> arr[i][2];
  }
  sort(arr.begin(), arr.end());
  for(int i = 1; i <= n; i++){
    s[i] = arr[i][1], e[i] = arr[i][0], p[i] = arr[i][2];
  }
  int dp[n + 1][2];
  memset(dp, 0, sizeof dp);
  for(int i = 1; i <= n; i++){
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
    int j = lower_bound(e, e + n + 1, s[i]) - e;
    if(e[j] >= s[i]) j--;
    dp[i][1] = max(dp[j][0], dp[j][1]) + p[i];
  }
  cout << max(dp[n][0], dp[n][1]);
  return 0;
}
