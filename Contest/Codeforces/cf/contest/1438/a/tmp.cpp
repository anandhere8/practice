#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
  int tt;
  cin >> tt;
  for(int cases = 1; cases <= tt; cases++){
    int n; cin >> n;
    vector < pair < int, int >> v(n);
    int X[n], Y[n];
    for(int i = 0; i < n; i++){
      cin >> X[i] >> Y[i];
      //swap(X[i], Y[i]);
      v[i] = {X[i], Y[i]};
    }
    sort(v.begin(), v.end());
    sort(Y, Y + n);
    sort(X, X + n);
    int y = Y[n / 2];
    int res = INT_MAX;
    int kk = 0;
    for(int i = X[0], j = 0; j < n; j++, i++){
      kk += abs(i - X[j]) + abs(v[j].second - y);
    }
    for(int i = -1000; i <= 10000; i++){
      int ans = n * abs(X[0] - i) + kk;
      res = min(ans, res);
    }
    cout << "Case #" << cases << ": " << res << endl;
  }
  return 0;
}
