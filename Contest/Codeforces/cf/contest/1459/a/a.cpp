#include<bits/stdc++.h>
#define int long long
using namespace std;

void test_case(){
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  int a = 0, b = 0;
  for(auto i = 0; i < n; ++ i){
    for(auto j = 0; j < n; ++ j){
      //if(s[i] == t[j]) continue;
      if(s[i] >= t[j]){
        a++;
      }
      else{
        b++;
      }
    }
  }
  if(a > b){
    cout << "RED";
  }
  else if(a < b) cout << "BLUE";
  else cout << "EQUAL";
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt = 1; 
  cin >> tt;
  while(tt--){
    test_case();
    cout << endl;
  }
  return 0;
}
