#include<bits/stdc++.h>
#define int long long
using namespace std;

void test_case(){
	int n, m;
  cin >> n >> m;
  int A[n + 2][m + 2];
  memset(A, 0, sizeof A);
  int res = 0;
  for(auto  i =  1;  i <=  n;  i++){
    string s;
    cin >> s;
    for(auto  j =  1; j <=  m; j++){
      // char c; cin >> c;
      if(s[j - 1] == '*'){
        A[i][j] = 1;
        A[i][j] += A[i][j - 1];
      }
    }
  }
  
  // for(auto i = 1; i <= n; ++ i){
  //   for(auto j = 1; j <= m; ++ j){
  //     cerr << A[i][j] << " ";
  //   }
  //   cerr << endl;
  // }
  for(auto  i =  1;  i <=  n;  i++){
    for(auto  j =  1; j <=  m; j++){
      int cnt = 0;
      if(A[i][j] == 0) continue;
      for(auto x = i; x <= n; ++ x, cnt += 1){
        int a = j - cnt, b = j + cnt;
        // cerr << a << " " << b << endl;
        if(a <= 0) break;
        if(b > m) break;
        if(A[x][b] - A[x][a - 1] == b - a + 1) {
          res++;
        }
        else break;
      }
    }
  }
  cout << res;
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt = 1; 
  cin >> tt;
  while(tt--){
    test_case();
    cout << endl;
  }
  return 0;
}
