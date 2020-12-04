#include <bits/stdc++.h>

using namespace std;

int main(){
  int n; cin >> n;
  bool ok = true;
  int ans = 1e8;
  for(int i = 2; i * i <= n; i++){
    if(n % i == 0){
      ok = false;
      int a = i, b = n / i;
      string c = to_string(a) + to_string(b);
      int num = stoi(c);
      ans = min(num, ans);
    }
  }
  if(ok || n == 1) cout << "Not Possible" << endl;
  else{
    cout << ans << endl;
  }
  return 0;
}
  
