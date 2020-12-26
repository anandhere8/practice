#include<bits/stdc++.h>
#define int long long
using namespace std;

void test_case(){
	int n, m;
  cin >> n >> m;
  string s = "";
  for(auto i = 0; i < m; ++ i){
    s += 'a';
  }
  m = n - m;
  for(auto i = 0; i < (m - m % 3) / 3; ++ i){
    s += "bca";
  }
  if(m % 3 == 1)
    s += 'b';
  if(m % 3 == 2)
    s += "bc";
  cout << s;
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
