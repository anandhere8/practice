#include <bits/stdc++.h>

using namespace std;

int main(){
  auto test = [&](){
    string s;
    cin >> s;
    int cnt0 = 0;
    int n = (int)s.size();
    int l = -1, r = -1;
    for(auto i = 0; i < n; ++ i){
      if(s[i] == '0'){
        r = i;
        cnt0++;
      }
      if(s[i] == '1' && l == -1){
        l = i;
      }
    }
    int cnt1 = n - cnt0;
    if(l == -1 || r == -1){
      cout << 0;
      return;
    }
    int ans = max(n - cnt1 - l, r - cnt0 + 1);
    string str = string(cnt1, '1') + string(cnt0, '0');
    if(s == str) ans++;
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