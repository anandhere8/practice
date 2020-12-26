#include<bits/stdc++.h>
#define int long long
using namespace std;

void test_case(){
  int n;
  cin >> n;
  vector<int> A;
  for(int i = 9; i ; i--){
    if(i <= n){
      A.emplace_back(i);
      n -= i;
    }
  } 
  if(n == 0){
    reverse(A.begin(), A.end());
    for(auto &xax : A){
      cout << xax ;
    }
  }
  else cout << -1;
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
