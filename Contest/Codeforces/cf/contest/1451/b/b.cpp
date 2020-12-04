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
  int n, q; cin >> n >> q;
  string s; cin >> s;
  while(q--){
    int l, r; cin >> l >> r;
    l--, r--;
    bool ok = false;
    for(int i = 0; i < l; i++){
      if(s[i] == s[l]){
        ok = true;
        break;
      }
    }
    for(int i = r + 1; i < n; i++){
      if(s[i] == s[r]){
        ok = true;
        break;
      }
    }
    if(ok) cout << "YES";
    else cout << "NO";
    cout << endl;
  } 
}

int32_t main(){
  IOS;
  int tt = 1; 
  cin >> tt;
  while(tt--){
    test_case();
    //cout << endl;
  }
  return 0;
}
