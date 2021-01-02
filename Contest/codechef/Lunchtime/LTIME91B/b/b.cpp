#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int tt = 1; 
  cin >> tt;
  auto test_case = [&](){
    string s, t;
    int n;
    cin >> n;
    cin >> s >> t;
    queue<int> stk;
    for(auto i = 0; i < n; ++ i){
      if(s[i] == '0'){
        stk.push(i);
      }
    }
    bool ok = true;
    for(auto i = 0; i < n; ++ i){
      if(s[i] != t[i]){
        if(s[i] == '1'){
          while((int)stk.size() && (stk.front() < i)) stk.pop();
          if((int)stk.size() == 0) {
            // cerr << "F";
            ok = false;
            break;
          }
          else{

            int x = stk.front(); stk.pop();

            swap(s[i], s[x]);
          }
        }
        else{
          ok = false;
          break;
        }
      }
    }
    if(ok) cout << "Yes";
    else cout << "No";
  };  
  while(tt--){
    test_case();
    cout << endl;
  }
  return 0;
}
