#include <bits/stdc++.h>
#define int long long
using namespace std;

int res;
int tot;
void solve(int i, int n, vector < int > &A, int sum){
  if(i == n){
    int rest = tot - sum;
    res = min(res, abs(sum - rest));
    return;
  }
  solve(i + 1, n, A, sum + A[i]);
  solve(i + 1, n, A, sum);
}

int32_t main(){
  int n;
  res = 1e9;
  cin >> n;
  vector < int > A(n);
  for(int i = 0; i < n; i++){
    cin >> A[i];
    tot += A[i];
  }
  solve(0, n, A, 0);
  cout << res;
  return 0;
}