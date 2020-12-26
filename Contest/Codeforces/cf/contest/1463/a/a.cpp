#include<bits/stdc++.h>
#define int long long
using namespace std;

void test_case(){
  int n = 3;
  int a[3];
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a + 3);
  int sum = 0;
  for(auto i = 0; i < n; ++ i){
    sum += a[i];
  }
  if(sum % (6 + n) == 0){
    int tmp = sum / (6 + n);
    if(tmp <= a[0]){
      cout << "YES";
    }
    else cout << "NO";
  }
  else
    cout << "NO";
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
