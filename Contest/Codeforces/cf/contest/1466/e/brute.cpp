#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> A(n);
  for(int i = 0; i < n; i++){
    // cin >> A[i];
  }
  long long res = 0;
  for(auto i = 0; i < n; ++ i){
    for(auto j = i + 1; j < n; ++ j){
      //for(auto k = j + 1; k < n; ++ k)
      {
        ++ res;
      }
    }
  }
  cout << res;
  return 0;
}