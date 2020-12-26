#include <bits/stdc++.h>

using namespace std;

int main(){
  
  int n;
  cin >> n;
  vector<array<int, 2>> A(n);
  for(auto i = 0; i < n; ++ i){
    cin >> A[i][0] >> A[i][1];
  }
  sort(A.begin(), A.end(), [&](array < int, 2 > a, array<int, 2> b){
    return a[1] < b[1];
  });
  int res = 0;
  int r = -1;
  for(auto i = 0; i < n; ++ i){
    if(A[i][0] >= r){
      res++;
      r = A[i][1];
    }
  }
  cout << res;
  return 0;
}