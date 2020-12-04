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
  if(n == 1){
    cout << 0;
    return;
  }
  if(n == 2){
    cout << 1;
    return;
  }
  if(n % 2 == 0 || n <= 3){
    cout << 2;
    return;
  }
  else{
    cout << 3;
    return;
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
