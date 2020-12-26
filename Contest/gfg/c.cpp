#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  vector < int > A(n + 1);
  for(auto i = 1; i < n + 1; ++ i){
    cin >> A[i];
    A[i] += A[i - 1];
  }
  int j = 0;
  int res = 1e9;
  for(int i = m; i < n; i++, j++){
    res = min(res, A[i] - A[j]);
  }
  cout << res;  
  return 0;
}