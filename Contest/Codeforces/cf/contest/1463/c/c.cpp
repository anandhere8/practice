#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
  auto test = [&](){
    int n;
    cin >> n;
    vector<int> t(n + 1, 1e18), x(n + 1, 1e18);
    for(auto i = 0; i < n; ++ i){
      cin >> t[i] >> x[i];
    }
    int curP = 0, curT = 0, desP = 0, ans = 0;
    for(auto i = 0; i < n; ++ i){
      int ti = t[i];
      int xi = x[i];
      if(abs(curP - desP) <= ti - curT){
        curP = desP;
        curT = ti;
        desP = xi;
      }
      auto ok = [&](int from, int mid, int to){
        return (from <= mid && mid <= to) || (to <= mid && mid <= from);
      };
      if(!ok(curP, xi, desP)){

      }
      else{
        int timeI = abs(xi - curP);
        if(timeI >= ti - curT && timeI <= t[i + 1] - curT){
          ++ ans;
        }
      }
    }
    cout << ans;
  };
  int tt;
  cin >> tt;
  while(tt--){
    test();
    cout << endl;
  }
  return 0;
}
