#include <bits/stdc++.h>

using namespace std;

int main(){
  int tt;
  cin >> tt;
  while(tt--){
    int n; cin >> n;
    int x = 0, cnt = 1, res = 0;
    while(x < n) 
      x += cnt, ++cnt, ++res;
    if(n == x - 1) ++res;
    cout << res << endl;
  }
  return 0;
}
