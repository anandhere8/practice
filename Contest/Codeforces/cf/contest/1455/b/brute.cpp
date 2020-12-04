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
  queue < pair < int, int >> que;
  que.push({0, 1});
  while(!que.empty()){
    auto &[x, y] = que.front(); que.pop();
    if(x == n){
      cout << y - 1;
      return;
    }
    que.push({x + y, y + 1});
    que.push({x - 1, y + 1});
  } 
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
