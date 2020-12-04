#include<bits/stdc++.h>

#define EB emplace_back
#define int long long
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

void test_case(){
  string s; cin >> s;
  int ans = 0, a = 0, b = 0;
  for(auto x : s){
    if(x == '('){
      a++;
    }
    if(x == '['){
      b++;
    }
    if(x == ')'){
      if(a){
        ans++;
        a--;
      }
    }
    if(x == ']'){
      if(b){
        ans++;
        b--;
      }
    }
  }
  cout << ans;
}

int32_t main(){
  IOS;
  int tt = 1; 
  cin >> tt;
  while(tt--){
    test_case();
    cout << endl;
  }
  return 0;
}
