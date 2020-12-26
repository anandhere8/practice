#include <bits/stdc++.h>

using namespace std;

int main(){
  string s;
  cin >> s;
  vector<int> f(26);
  for(auto x : s){
    f[x - 'A']++;
  }
  int ok = 0;
  for(auto i = 0; i < 26; ++ i){
    if(f[i] % 2) ok ++;
  }
  if(ok > 1){
    cout << "NO SOLUTION";
    return 0;
  }
  string a = "", b = "";
  char special = ' ';
  int cnt = 0;;
  for(auto i = 0; i < 26; ++ i){
    if(f[i] % 2){
      special = 'A' + i;
      cnt = f[i];
      continue;
    }
    for(auto j = 0; j < f[i] / 2; ++ j){
      a += ('A' + i);
    }
    for(auto j = f[i] / 2; j < f[i]; ++ j){
      b += ('A' + i);
    }
  }
  assert((int)a.size() == (int)b.size());
  reverse(b.begin(), b.end());
  cout << a;
  if(cnt) while(cnt--) cout << special;
  cout << b;
  return 0;
}
