#include<bits/stdc++.h>
#define int long long
using namespace std;

void test_case(){
	int n;
	cin >> n;
	string s;
  cin >> s;
  int cnt = 0;
  for(int i = n - 1; i >= 0; i--){
    if(s[i] == ')') cnt++;
    else break;
  }
  if(cnt > n - cnt) cout << "Yes";
  else cout << "No";
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
