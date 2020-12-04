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
  map < int, int > mp, mpp;
  int A[n];
  int ans = -1;
  for(int i = 0; i < n; i++){
    cin >> A[i];
    mp[A[i]]++;
    mpp[A[i]] = i;
  }
  sort(A, A + n);
  for(int i = 0; i < n; i++){
    if(mp[A[i]] == 1){
      cout << mpp[A[i]] + 1;
      return;
    }
  }
  cout << -1;
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
