#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  map<int, int > mp;
  for(auto i = 0; i < n; ++ i){
    int a, b;
    cin >> a >> b;
    mp[a]++, mp[b + 1]--;
  }
  int cnt = 0;
  for(auto &x : mp){
    x.second += cnt;
    cnt = x.second;
  }
  int res = 0;
  for(auto x : mp){
    res = max(res, x.second);
  }
  cout << res << endl;
  return 0;
}