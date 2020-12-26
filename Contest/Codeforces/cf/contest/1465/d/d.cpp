#include<bits/stdc++.h>
#define int long long
using namespace std;

int n, x, y;
string s;

int solve(int i, int f){
  if(i == n){
    return 0;
  }
  int res = 0;
  int ans ;
  if(s[i] == '1'){
    if(!f){
      ans = x;
    }
    ans += solve(i + 1, 1);
    res = ans;
  }
  else if(s[i] == '0'){
    if(f)
      ans = y;
    ans += solve(i + 1, 0);
    res = ans;
  }
  else {
    int a = 0, b = 0;
    if(f){
      a = y + solve(i + 1, 0);
      b = solve(i + 1, 1);
    }
    else{
      a = solve(i + 1, 0);
      b = y + solve(i + 1, 1);
    }
    res = min(a, b);
  }
  return res;
}

void test_case(){
	cin >> s;
  cin >> x >> y;
  n = s.size();
  int ans;
  if(s[0] == '?'){
    ans = min(solve(1, 0), solve(1, 1));
  }
  else
    ans = solve(1, s[0] - '0');
  cout << ans;
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt = 1; 
  //cin >> tt;
  while(tt--){
    test_case();
    cout << endl;
  }
  return 0;
}
