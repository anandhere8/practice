#include<bits/stdc++.h>

#define EB emplace_back
#define int long long
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

int lcm(int a, int b){
  return a * (b / __gcd(a, b));
}

void test_case(){
  int k, x; cin >> k >> x;
  int ans = INT_MAX;
  for(int i = 1; i <= x; i++){
    for(int j = 1; j <= x; j++){
      for(int ii = 1; ii <= x; ii++){
        //for(int jj = 1; jj <= x; jj++)
        {
            if(lcm(i, lcm(j, ii)) == x)
              ans = min(ans, i + j + ii);
        }
      }
    }
  } 
  cout << ans;
}

int32_t main(){
  IOS;
  int tt = 1; 
  cin >> tt;
  while(tt--){
    test_case();
    cout << endl;
  }
  return 0;
}
