#include<bits/stdc++.h>
#define int long long
using namespace std;

void test_case(){
	int n;
  cin >> n;
  int k; cin >> k;
  vector<pair<int, int>> A(n + 1);
  for(auto i = 0; i <= n; ++ i){
    cin >> A[i].first;
    A[i].second = i;
  }
  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());
  
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
