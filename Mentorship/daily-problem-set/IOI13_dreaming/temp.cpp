#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
  int a, b;
  cin >> a >> b;
  if(b - a < 100000){
    int ans = 1;
    for(int i = a + 1; i <= b; i++){
      ans *= i % 10;
      ans %= 10;
    }
    cout << ans;
  }
  else cout << 0;
  return 0;
}