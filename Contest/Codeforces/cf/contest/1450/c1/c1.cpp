#include <bits/stdc++.h>

using namespace std;

int main(){
  auto solve = [&](){
    int n;
    cin >> n;
    vector < string > A(n);
    for(int i = 0; i < n; i++){
      cin >> A[i];
    }
    int f[3] = {};
    int k = 0, change = 0;
    for(auto i = 0; i < n; ++ i){
      for(auto j = 0; j < n; ++ j){
        if(A[i][j] == 'X'){
          k++;
          f[(i + j) % 3]++;
        }
      }
    }
    int id = min_element(f, f + 3) - f;
    for(auto i = 0; i < n; ++ i){
      for(auto j = 0; j < n; ++ j){
        if(A[i][j] == 'X' && (i + j) % 3 == id){
          A[i][j] = 'O';
          change++;
        }
      }
    }
    for(auto &xax : A){
      cout << xax << endl;
    }
    assert(change <= k / 3);
  };

  int tt;
  cin >> tt;
  while(tt--){
    solve();
  }
  return 0;
}