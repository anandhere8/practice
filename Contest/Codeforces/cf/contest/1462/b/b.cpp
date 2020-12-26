#include<bits/stdc++.h>
#define int long long
using namespace std;

void test_case(){
	int n;
	cin >> n;
	string s;
  cin >> s;
	for(int i = 0; i <= 4; i++){
    string tmp = s.substr(0, i);
    string b = "";
    for(int j = n - (4 - i); j < n; j++){
      b += s[j];
    }
    // cerr << tmp << " " << b << endl;
    tmp += b;
    if(tmp == "2020"){
      cout << "Yes";
      return;
    }
  }
  cout << "No";
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
