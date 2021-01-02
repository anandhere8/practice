#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int tt = 1; 
  cin >> tt;
  
  auto test_case = [&](){
    int n;
    cin >> n;
    int m = n;
    cin >> m;
    int A[n + 1][m + 1], B[n + 1][m + 1];
    memset(B, 0, sizeof(B));
    for(int i = 0; i < n; ++ i){
      for(int j = 0; j < m; ++ j){
        cin >> A[i][j];
        //B[i + 1][j + 1] += A[i][j];

      }
    }
    int qq; cin >> qq;
    int lst_a = -1, lst_b = -1;
    while(qq--){
      int a, b, c;
      cin >> a >> b >> c;
      a--, b--;
      int x = A[a][b];
      A[a][b] = c;
      bool ok = true;
      for(int i = 1; i < n; ++ i){
        for(int j = 1; j < m; ++ j){
          if(A[i][j] != A[i - 1][j - 1]){
            ok = false;
            break;
          }
          if(!ok) break;
        }
      }
      if(ok){
        cout << "Yes";
      }
      else cout << "No";
      cout << endl;
    }
  };  
  while(tt--){
    test_case();
    // cout << endl;
  }
  return 0;
}
