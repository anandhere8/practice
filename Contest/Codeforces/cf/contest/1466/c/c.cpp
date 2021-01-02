#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int tt = 1; 
  cin >> tt;
  // Focus
  auto test_case = [&](){
    string s;
    cin >> s;
    int n = (int)s.size();
    map<int, int> mp;
    int ans = 0;
    for(auto i = 0; i < n; ++ i){
      bool ok = true;
      if(mp.count(s[i])){
        int lst = mp[s[i]];
        lst = i - lst;
        if(lst <= 2) ++ ans, ok = false;
      }
      if(ok) mp[s[i]] = i;
    }
    cout << ans;
  };  
  while(tt--){
    test_case();
    cout << endl;
  }
  return 0;
}
