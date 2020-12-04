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
  int n; cin >> n;
  map < int, int > mp;
  int mx = 0;
  for(int i = 2; i * i <= n; i++){
    if(n % i == 0){
      int cnt = 0;
      while(n % i == 0){
        cnt++;
        n /= i;
      }
      mp[i] = cnt;
      mx = max(mx, cnt);
    }
  }
  if(n > 1) {
    mp[n]++;
    mx = max(mx, 1ll);
  }
  int sz = 0;
  vector < int > v(mx, 1);
  for(auto x : mp){
    int num = x.F;
    int cnt = x.S;
    for(int i = mx - 1; i >= 0 && cnt; i--, cnt--){
      v[i] *= num;
    }
  }
  cout << (int)v.size() << endl;
  for(auto x : v) cout << x << " ";
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
