#include <iostream>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int main(){
  IOS;
  int tt; cin >> tt;
  while(tt--){
    int n; cin >> n;
    int A[n], P[n], S[n + 1];
    for(int i = 0; i < n; i++){
      cin >> A[i];
      P[i] = A[i];
      S[i] = A[i];
      if(i > 0){
        P[i] = max(P[i - 1], P[i]);
      }
    }
    for(int i = n - 2; i >= 0; i--){
      S[i] = max(S[i], S[i + 1]);
    }
    bool ok = false;
    for(int i = 0; i < n - 2; i++){
      int mn = 1e9 + 2;
      int cnt = 0;
      for(int j = i + 1; j < n - 1; j++, cnt++){
        mn = min(mn, A[j]);
        if(mn == P[i] && mn == S[j + 1]){
          cout << "YES" << endl;
          cout << i + 1 << " " << cnt + 1 << " " << n - i - 1 - cnt - 1 << endl;
          ok = true;
          break;
        }
        if(mn < P[i]) {
          i = j;
          break;
        }
        if(ok) break;
      }
      if(ok) break;
    }
    if(!ok)
      cout << "NO" << endl;
  }
  return 0;
}
    
