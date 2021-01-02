#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int tt = 1; 
  cin >> tt;
  auto test_case = [&](){
    string s;
    cin >> s;
    if((int)s.size() % 2){
      cout << "NO";
    }
    else{
      int n = (int)s.size();
      int l = n, r = n;
      if(s[0] == ')' || s.back() == '(') cout << "NO";
      else cout << "YES";
    }
    return 0;
  };  
  while(tt--){
    test_case();
    cout << endl;
  }
  return 0;
}
