#include <bits/stdc++.h>

using namespace std;

int main(){
  string s;
  cin >> s;
  map<int, vector<int>> mp;
  for(auto xax = 0; xax < (int)s.size(); ++ xax){
    mp[s[xax]].emplace_back(xax);
  }
  int n = (int)s.size();
  int ans = n;
  for(auto &vx : mp){
    int l = -1;
    int res = 0;
    vx.second.emplace_back(n);
    for(auto x : vx.second){
      res = max(res, x - l + 1);
      l = x;
    }
    ans = min(ans, res - 1);
  }
  cout << ans << endl;
  return 0;
}