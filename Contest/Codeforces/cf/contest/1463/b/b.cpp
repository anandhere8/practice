#include<bits/stdc++.h>
#define int long long
using namespace std;

int get(int n){
  int x = 1;
  while(x <= n){
    x *= 2;
  }
  return x / 2;
}

void test_case(){
	int n;
  cin >> n;
  vector < int > A(n);
  int sum = 0;
  for(int i = 0; i < n; i++){
    cin >> A[i];
    sum += A[i];
  }
  vector<int> ans(n);
  int sm = 0;
  for(auto i = 0; i < n; ++ i){
    ans[i] = get(A[i]);    
    sm += abs(ans[i] - A[i]);
  }  
  assert(2 * sm <= sum);
  for(auto &xax : ans){
    cout << xax << " ";
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
