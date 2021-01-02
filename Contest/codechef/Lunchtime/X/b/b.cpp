#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int main(){
  IOS;
  int tt = 1;//  cin >> tt;
  while(tt--){
    int n; cin >> n;
    int ans = 0;
    //int mx = 0;
    for(int i = 1; i <= n; i++){
      for(int j = i + 1; j <= min(i + 2005, n); j++){
        int num = i * j + i;
        int dem = i * j + j;
        int g = __gcd(num, dem);
        num /= g, dem /= g;
        if(num == dem - 1) {
          //cerr << i << " " << j << endl;
          ans++;
        }
      }
      for(int j = n; j > i + 2005; j--){
        int num = i * j + i;
        int dem = i * j + j;
        int g = __gcd(num, dem);
        num /= g, dem /= g;
        if(num == dem - 1) {
          //cerr << i << " " << j << endl;
          ans++;
        }
      }
    }
    //cerr << mx  << endl;
    cout << ans;
  }
  return 0;
}
