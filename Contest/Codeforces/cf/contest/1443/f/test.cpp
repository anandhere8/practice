#include <bits/stdc++.h>

using namespace std;

int ans;

void solve(int i, int x, int n, int sum){
  if(i > 9){
    if(sum == n){
      ans = min(ans, x);
    }
    return;
  }
  solve(i + 1, x * 10 + i, n, sum + i);
  solve(i + 1, x, n, sum);
}

void test(){
  ans = 1e9;
  int n;
  cin >> n;
  solve(1, 0, n, 0);
  if(ans == 1e9) ans = -1;
  cout << ans;
}

int main(){
  int tt;
  cin >> tt;
  while(tt--){
    test();
    cout << endl;
  }
  return 0;
}