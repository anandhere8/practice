#include<bits/stdc++.h>
#define int long long
using namespace std;

void test_case(){
	int n, m;
  cin >> n >> m;
  vector < int > A(n), B(m);
  int g = 0;

  for(int i = 0; i < n; i++){
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  for(int i = 1; i < n; i++){
    g = __gcd(g, A[i] - A[i - 1]);
  }
  // cout << g << " ";
  for(int i = 0; i < m; i++){
    cin >> B[i];
    cout << __gcd(g, B[i] + A[0]) << " ";
  }

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
