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
  string s, t;
  int n;
  cin >> s >> t;
  n = s.size();
  int cnt = 0;
  for(int i = 0; i < n; i++){
    if(s[i] == t[i]) continue;
    int j = i;
    cnt++;
    while(j < n && s[j] != t[j]){
      s[j] = t[j];
      j += 2;
    }
  }
  cout << cnt;
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
