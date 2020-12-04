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
  int n, m, k; cin >> n >> m >> k;
  int cnt = 0;
  for(int i = 0; i < n; i++){
    int sum = 0;
    for(int j = 0; j < k; j++){
      int x; cin >> x;
      sum += x;
    }
    int q; cin >> q;
    if(sum >= m && q <= 10){
      cnt++;
    }
  }
  cout << cnt;
}

int32_t main(){
IOS;
int tt = 1; 
//cin >> tt;
while(tt--){
  test_case();
  cout << endl;
}
return 0;
}
