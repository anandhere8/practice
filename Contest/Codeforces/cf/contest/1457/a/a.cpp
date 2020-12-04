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
  int n, m, a, b; cin >> n >> m >> a >> b;
  int ans = 0;
  ans = max(ans, abs(n - a) + abs(m - b));
  ans = max(ans, abs(1 - a) + abs(1 - b));
  ans = max(ans, abs(1 - a) + abs(1 - b));
  ans = max(ans, abs(1 - a) + abs(m - b));
  ans = max(ans, abs(n - a) + abs(1 - b));
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
