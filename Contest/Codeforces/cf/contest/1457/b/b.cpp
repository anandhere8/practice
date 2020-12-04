#include<bits/stdc++.h>

#define EB emplace_back
#define int long long
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

void test_case(){
  int n, k; cin >> n >> k;
  int ans = LLONG_MAX;
  int A[n];
  for(int i = 0; i < n; i++){
    cin >> A[i];
  }
  for(int color = 1; color <= 100; color++){
    int cnt = 0;
    for(int i = 0; i < n; i++){
      if(A[i] != color){
        cnt++;
        i += k - 1;
      }
    }
    ans = min(ans, cnt);
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
