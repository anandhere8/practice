#include <bits/stdc++.h>

using namespace std;

void solve(){
  int n;
  cin >> n;
  vector < string > A(n);
  int k = 0;
  int cnt[3][2] = {{}, {}, {}};
  for(int i = 0; i < n; i++){
    cin >> A[i];
    for(auto j = 0; j < n; ++ j){
      if(A[i][j] == '.') continue;
      k++;
      cnt[(i + j) % 3][!((A[i][j] + 'O' - 1) / 'O' - 1)]++;
    }
  }
  for(auto x = 0; x < 3; ++ x){
    for(auto y = 0; y < 3; ++ y){
      if(x == y) continue;
      if(cnt[x][0] + cnt[y][1] <= k / 3){
        for(auto i = 0; i < n; ++ i){
          for(auto j = 0; j < n; ++ j){
            if((i + j) % 3 == x && A[i][j] == 'X'){
              A[i][j] = 'O';
            }
            if((i + j) % 3 == y && A[i][j] == 'O'){
              A[i][j] = 'X';
            }
          }
          cout << A[i] << endl;
        }
        return;
      }
      
    }
  }
}

int main(){
  int tt;
  cin >> tt;
  while(tt--){
    solve();
  }
  return 0;
}