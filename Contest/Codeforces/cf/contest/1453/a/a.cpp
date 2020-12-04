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
  int n, m; cin >> n >> m;
  int a[105] = {}, b[105] = {};
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    a[x]++;
  }
  for(int i = 0; i < m; i++){
    int x; cin >> x;
    b[x]++;
  }
  int res = 0;
  for(int i = 0; i < 105; i++){
    res += min(a[i], b[i]);
  }
  cout << res;
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
