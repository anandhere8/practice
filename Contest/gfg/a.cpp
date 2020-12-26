#include <bits/stdc++.h>

using namespace std;

int main(){
  int tt;
  cin >> tt;
  while(tt--){
    int a, b; 
    cin >> a >> b;
    vector < int > A, B;
    map < int, int > mp;
    int cnt = 0;
    while(a){
      A.emplace_back(a);
      mp[a] = cnt++;
      a /= 2;
    }
    int res = 0;
    while(b){
      if(mp.count(b)){
        res += mp[b];
        break;
      }
      b /= 2;
      res++;
    }
    cout << res << endl;
  }
  return 0;
}