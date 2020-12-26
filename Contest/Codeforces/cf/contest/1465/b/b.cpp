#include<bits/stdc++.h>
#define int long long
using namespace std;

// A trash problem .

void test_case(){
  int n;
  cin >> n;
  
  auto ok = [&](int x){
    int tmp = x, r;
    while(x){
      int r = x % 10;
      if(r > 0 && tmp % r){
        return false;
      }
      x /= 10;
    }
    return true;
  };
  
  for(int i = n; ;i++){
    if(ok(i)){
      cout << i;
      return;
    }
  }
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt = 1; 
  cin >> tt;
  while(tt--){
    test_case();
    cout << endl;
  }
  return 0;
}
