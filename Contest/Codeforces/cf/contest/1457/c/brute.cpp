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
  int n, p, k; cin >> n >> p >> k;
  p--;
  string s; cin >> s;
  int x, y; cin >> x >> y;
  int yy = 0;
  int ans = LLONG_MAX;
  for(int i = p; i < n; i++){
    int cnt = yy;
    for(int j = i; j < n; j += k){
      if(s[j] == '0') cnt += x;
    }
    ans = min(ans, cnt);
    yy += y;
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
