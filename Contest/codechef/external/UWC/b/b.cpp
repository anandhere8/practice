#include<bits/stdc++.h>
#define int long long
using namespace std;

void test_case(){
  int n, m;
  cin >> n >> m;
  vector < int > A(n), B(m);
  for(int i = 0; i < n; i++){
    cin >> A[i];
  }
  map<int, int> mp;
  for(int i = 0; i < m; i++){
    cin >> B[i];
    mp[B[i]]++;
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  int res = 0;
  int cnt = 0;
  for(auto x : B){
    if(x < A[0]) cnt++;
  }
  cout << cnt * n << endl;
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
