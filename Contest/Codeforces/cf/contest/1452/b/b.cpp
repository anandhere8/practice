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
  int n; cin >> n;
  int A[n];
  int sum = 0, cnt = 0;
  for(int i = 0; i < n; i++){
    cin >> A[i];
    sum += A[i];
  }
  int m = sum % (n - 1);
  int ans = cnt;
  if(m){
    ans += n - 1 - m;
  }
  sort(A, A + n);
  if(A[0] == A[n - 1] && A[0] == 0){
    ans = 0;
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
