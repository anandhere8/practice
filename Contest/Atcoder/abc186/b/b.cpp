#include<bits/stdc++.h>
#define int long long
using namespace std;

void test_case(){
	int n, m;
  cin >>  n >> m;
  int A[n + 1][m + 1];
  int ans = 1e9 ;
  for(auto  i =  1;  i <=  n;  i++){
    for(auto  j =  1; j  <=  m; j++){
      cin >> A[i][j];
      ans = min(ans, A[i][j]);
    }
  }
  int res = 0;
  for(auto  i =  1;  i <=  n;  i++){
    for(auto  j =  1; j <=  m; j++){
      res += A[i][j] - ans;
    }
  }
  cout << res;
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt = 1; 
  // cin >> tt;
  while(tt--){
    test_case();
    cout << endl;
  }
  return 0;
}
