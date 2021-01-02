#include <bits/stdc++.h>

using namespace std;

auto fac_foo(int x){
  vector<int> v;
  for(int i = 1; 1ll * i * i <= x; ++ i){
    if(x % i == 0){
      v.emplace_back(i);
      if(i == x / i) continue;
      v.emplace_back(x / i);
    }
  }
  return v;
}

int main(){
  
  auto testcase = [&](){
    int n, m;
    cin >> n >> m;
    swap(n, m);
    vector<int> A(n);
    int g = 0;
    for(int i = 0; i < n; i++){
      cin >> A[i];
      g = __gcd(g, A[i]);
    }
    auto vec = fac_foo(g);
    g = 0;
    for(auto x : vec){
      if(x <= m){
        g = max(g, x);
      }
    }
    cout << m - g << '\n';
  };

  int tt = 1;
  cin >> tt;
  while(tt--){
    testcase();
  }
  return 0;
}