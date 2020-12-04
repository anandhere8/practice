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
  string s; cin >> s;
  int x, y; cin >> x >> y;
  int ans = LLONG_MAX;
  for(int i = p - 1; i < min(p + k - 1, n); i++){
    vector < int > tmp;
    for(int j = i; j < n; j += k){
      tmp.EB(!(s[j] - '0'));
    }
    for(int j = (int)tmp.size() - 2; j >= 0; j--){
      tmp[j] += tmp[j + 1];
    }
    int j0 = 0;
    for(int j = i; j < n; j += k){
      ans = min(ans, (j - p + 1) * y + x * tmp[j0++]);
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
