#include <bits/stdc++.h>

using namespace std;

int main(){
  int n; cin >> n;
  int A[n + 1], pre[n + 1] = {};
  for(int i  = 1; i <= n;i++){
    cin >> A[i];
  }
  for(int i = 1; i <= n; i++){
    pre[i] = pre[i - 1] ^ A[i];
  }
  if(n > 70){
    cout << 1 << endl;
    return 0;
  }
  int ans = n + 2;
  
  for(int i = 0; i <= n; i++){
    for(int j = i + 1; j <= n; j++){
      for(int k = j + 1; k <= n; k++){
        if((pre[i] ^ pre[j]) > (pre[j] ^ pre[k])){
          //cerr << i << " " << j << " : " << (pre[i] ^ pre[j]) << " " << (pre[j] ^ pre[k]) <<endl;
          ans = min(ans, k - i - 2);
        }
      }
    }
  }
  if(ans > n) ans = -1;
  cout << ans;
  return 0;
}
