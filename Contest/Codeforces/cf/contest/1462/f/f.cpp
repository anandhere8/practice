#include <bits/stdc++.h>

using namespace std;

int main(){
  auto test = [&](){
    int n;
    cin >> n;
    vector<array<int, 2>> A(n);
    vector<int> a(n + 1), b(n + 1);
    for(auto i = 0; i < n; ++ i){
      cin >> A[i][0] >> A[i][1];
      a[i + 1] = A[i][0];
      b[i + 1] = A[i][1];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = n;
    for(auto i = 0; i < n; ++ i){
      int r = lower_bound(a.begin(), a.end(), A[i][1] + 1) - a.begin();
      int l = lower_bound(b.begin(), b.end(), A[i][0]) - b.begin();
      l--, r = n - r + 1;
      ans = min(ans, l + r);
    }
    cout << ans;
  };

  int tt = 1;
  cin >> tt;
  while(tt--){
    test();
    cout << endl;
  }
  return 0;
}