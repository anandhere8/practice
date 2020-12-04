#include<bits/stdc++.h>

using namespace std;

int main(){
  int l, r;
  cin >> l >> r;
  int ans = 0;
  vector < vector < int >> v(r);
  for(int i = 0; i < r; i++){
    int n; cin >> n;
    v[i].push_back(0);
    while(n--){
      int x; cin >> x;
      x += v[i].back();
      v[i].push_back(x);
    }
  }
  for(int i = 1; i <= l; i++){
    bool ok = true;
    for(int j = 0; j < r; j++){
      int sum1 = 0, sum2 = 0;
      int idx = lower_bound(v[j].begin(), v[j].end(), i) - v[j].begin();
      idx--;
      sum2 = v[j].back() - v[j][idx];
      if(l - i < sum2){
        ok = false;
      }
      if(!ok) {
        //cout << "break for " << i << " " << j << endl;
        break;
      }
    }
    if(ok) ans++;
  }
  cout << l - ans << endl;
  return 0;
}


    
