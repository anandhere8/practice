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
  int n, a, b, h;
  cin >> n >> a >> b >> h;
  string s; cin >> s;
  int cnt0 = 0, cnt1 = 0;
  for(char c : s){
    if(c == '0') cnt0++;
    else cnt1++;
  }
  if(a + h < b) b = a + h;
  else if(b + h < a) a = b + h;
  int ans = cnt0 * a + cnt1 * b;
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
