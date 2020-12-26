#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt = 1; 
  cin >> tt;
  
  auto test_case = [&](){
    int x, y, k, n;
    cin >> x >> y >> k >> n;
    if(abs(x - y) % (2 * k) == 0 && n >= 2 * k){
      cout << "Yes";
    }
    else{
      cout << "No";
    }
  }; 
  while(tt--){
    test_case();
    cout << endl;
  }
  return 0;
}
