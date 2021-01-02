#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int tt = 1; 
  cin >> tt;
  vector<int> F(26);
  F[0] = 1;
  for(auto i = 1; i < 26; ++ i){
    F[i] = 2 * F[i - 1];
  }
  auto test_case = [&](){
    int n, k;
    cin >> n >> k;
    vector<int> res;
    int T = n;
    swap(n, k);
    bool ok = true;
    for(auto i = 25; i >= 0 && k > 0 && n > 0;){
      if(F[i] * k >= n){
        // cerr << i << endl;
        while((n - F[i]) >= (k - 1) && k > 0){
          k--;
          n -= F[i];
          res.emplace_back(i);
        }
        i--;
      }
      else{
        ok = false;
        break;
      }
    }
    if(!ok || n) cout << -1;
    else{
      for(auto &xax : res){
        cout << (char)(xax + 'a');
      }
    }
  };  
  while(tt--){
    test_case();
    cout << endl;
  }
  return 0;
}
