#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int tt = 1; 
  cin >> tt;
  
  auto test_case = [&](){
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
      cin >> A[i];
      sum += A[i];
    }
    if(sum % m == 0){
      cout << 0;
    }
    else cout << 1;
  };  
  while(tt--){
    test_case();
    cout << endl;
  }
  return 0;
}
