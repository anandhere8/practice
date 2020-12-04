#include <bits/stdc++.h>

using namespace std;

set < long long > st;

void factors(long long x){
  for(int i = 2; 1ll * i * i <= x; i++){
    if(x % i == 0){
      st.insert(i);
      while(x % i == 0) x /= i;
    }
  }
  if(x > 1) st.insert(x);
}

int main(){
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());   
  int n, acc = 20;
  long long A[200010], idx, res, ans;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%lld", A + i);
  }
  ans = n;
  while(acc--){
    idx = A[rng() % n];
    factors(idx), factors(idx + 1), factors(idx - 1);
  }
  for(long long x : st){
    res = 0;
    for(int i = 0; i < n; i++){
      if(A[i] < x) res += x - A[i];
      else{
        res += min(A[i] % x, x - A[i] % x);
      }
      if(res > n) break;
    }
    //cout << x << " " << res << endl;
    ans = min(ans, res);
  }
  printf("%lld\n", ans);
  return 0;
}
