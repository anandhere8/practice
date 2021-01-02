#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int tt = 1; 
  cin >> tt;
  
  auto test_case = [&](){
    int n;
    cin >> n;
    vector<int> A(n + 1);
    for(auto i = 0; i <= n; ++ i){
      A[i] = i;
    }
    int j = n;
    vector<pair<int, int>> v;
    int i;
    for(i = n - 1; i > 2; -- i){
      int x = i - 1;
      if(x * x < j){
        v.emplace_back(j, i);
        v.emplace_back(j, i);
        j = i;
      }
      else{
        v.emplace_back(i, j);
      }
    }
    int x = j;
    while(x > 1){
      v.emplace_back(j, i);
      x = (x + i - 1) / i;
    }
    int len = (int)v.size();
    assert(len <= n + 5);
    cout << len << endl;
    for(auto &xax : v){
      cout << xax.first << " " << xax.second << endl;
    }
    // cout << len << endl;
  };  
  while(tt--){
    test_case();
    // cout << endl;
  }
  return 0;
}
