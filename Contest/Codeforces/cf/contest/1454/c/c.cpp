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
  map < int, vector < int >> mp;
  for(int i = 0; i < n; i++){
    cin >> A[i];
    A[i]--;
    mp[A[i]].EB(i);
  }
  int ans = n;
  for(auto x : mp){
    vector < int > tmp;
    tmp.EB(-1);
    int qq = 0;
    for(auto y : x.S) tmp.EB(y);
    tmp.EB(n);
    for(int j = 1; j < (int)tmp.size(); j++){
      int c = tmp[j] - tmp[j - 1];
      if(c > 1) qq++;
    }      
    ans = min(ans, qq);
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
