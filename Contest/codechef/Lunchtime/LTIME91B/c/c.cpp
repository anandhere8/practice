#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int tt = 1; 
  cin >> tt;
  
  auto test_case = [&](){
    string s;
    cin >> s;
    int f[26] = {};
    int res = 0;
    for(auto x : s){
      f[x - 'a']++;
    }
    int sum = 0;
    vector<int> v;
    for(int i = 0; i < 26; i++){
      sum += f[i];
      res = max(res, f[i]);
      if(f[i]) v.emplace_back(f[i]);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int l = 0, r = (int)v.size() - 1;
    res = 0;
    while(l < r){
      int x = v[l] / 2;
      if(v[l] == 1) break;
      int y = 0;
      while(l < r && y + v.back() <= x){
        y += v.back();
        // cerr << l << " " << r << endl;
        r--;
        v.pop_back();
      }
      // cerr << x << " " << y << endl;
      res += y;
      v[l] -= 2 * y;
      res += v[l] / 3;
      v[l] %= 3;
      assert(v[l] >= 0);
      if(v[l]){
        r++;
        v.emplace_back(v[l]);
      }
      l++;
    }
    if(l == r){
      res += v[l] / 3;
    }
    cout << res;
  };  
  while(tt--){
    test_case();
    cout << endl;
  }
  return 0;
}
