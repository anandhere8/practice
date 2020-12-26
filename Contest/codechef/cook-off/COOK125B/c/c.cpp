#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt = 1; 
  cin >> tt;
  
  auto test_case = [&](){
    string s;
    cin >> s;
    int n = (int)s.size();
    if(n % 2){
      cout << -1;
    }
    else{
      vector<char> v;
      bool ok = false;
      for(auto x : s){
        if((int)v.size() && (v.back() != x)){
          ok = true;
          v.pop_back();
        }
        else{
          v.emplace_back(x);
        }
      }
      if(ok){
        cout << (int)v.size() / 2;
      }
      else cout << -1;
    }
  }; 
  while(tt--){
    test_case();
    cout << endl;
  }
  return 0;
}
