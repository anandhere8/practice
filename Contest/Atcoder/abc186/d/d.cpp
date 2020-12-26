#include<bits/stdc++.h>
#define int long long
using namespace std;

void test_case(){
	int n;
  cin >> n;
  vector<int> arr(n);
  for(auto i = 0; i < n; ++ i){
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());
  int sum = 0; 
  for (int i=n-1; i>=0; i--) 
      sum += i*arr[i] - (n-1-i)*arr[i]; 
  cout << sum;
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
