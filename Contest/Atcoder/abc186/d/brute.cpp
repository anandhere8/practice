#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector < int > A(n);
  for(int i = 0; i < n; i++){
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  int res = 0;
  for(auto i = 0; i < n; ++ i){
    for(auto j = i + 1; j < n; ++ j){
      res += abs(A[i] - A[j]);
    }
  }
  cout << res;
  return 0;
}