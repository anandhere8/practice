#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int tt = 1; 
  cin >> tt;
  
  auto test_case = [&](){
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    for(int i = 0; i < n; i++){
      cin >> A[i];
    }
    int l = A[0], r = A[0] + m;
    bool ok = true;
    for(auto i = 1; i < n - 1; ++ i){
      // cerr << l << " " << r << endl;
      if(A[i] + m + m - 1 <= l || r <= A[i]){
        ok = false;
        // cerr << i << endl;
        break;
      }
      else{
        l = max(A[i], l + 1 - m);
        r = min(A[i] + m - 1 + m, r - 1 + m);
      }
    }
    if(A[n - 1] + m <= l || r <= A[n - 1]){
      ok = false;
    }
    if(ok) cout << "YES";
    else cout << "NO";
  };  
  while(tt--){
    test_case();
    cout << endl;
  }
  return 0;
}
