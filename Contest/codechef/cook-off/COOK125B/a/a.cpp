#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt = 1; 
  cin >> tt;
  
  auto test_case = [&](){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for(auto x : s){
      cnt += x - '0';
    }
    cnt += 120 - n;
    if(cnt >= 90) cout << "YES";
    else cout << "NO";
  };
  while(tt--){
    test_case();
    cout << endl;
  }
  return 0;
}
