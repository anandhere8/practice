#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int tt = 1; 
  cin >> tt;
  
  auto test_case = [&](){
    int n, m;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++){
      cin >> A[i];
    }
    cin >> m;
    vector<int> B(m);
    int sum = 0, res = 0;;
    for(int i = 0; i < m; i++){
      cin >> B[i];
      sum += B[i];
      res = max(sum, res);
    }
    // cerr << res << endl;/
    int ans = res;
    for(auto i = 0; i < n; ++ i){
      res += A[i];
      ans = max(res, ans);
    }
    cout << ans;
  };  
  while(tt--){
    test_case();
    cout << endl;
  }
  return 0;
}
