#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector < int > A(n);
  long long res = -1e9 - 2;
  for(int i = 0; i < n; i++){
    cin >> A[i];
    res = max(res, 1ll * A[i]);
  }
  long long mx = 0;
  for(auto &xax : A){
    mx += xax;
    res = max(res, mx);
    mx = max(mx, 0ll);
  }
  cout << res;
  return 0;
}