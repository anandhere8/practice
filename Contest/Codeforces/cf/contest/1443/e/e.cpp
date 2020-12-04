#include <bits/stdc++.h>

using namespace std;

const int N_ = 14;
long long F[N_ + 1];

int A[N_];
void init(){
  F[0] = 1;
  for(int i = 1; i <= N_; i++){
    F[i] = i * F[i - 1];
  }
}

void genperm(long long k){
  int ok[N_] = {};
  for(int i = 0; i < N_; i++){
    int a = k / F[N_ - i - 1];
    k %= F[N_ - i - 1];
    int j = 0;
    while(ok[j] || a--){
      j++;
    }
    ok[j] = true;
    A[i] = j;
  }
}
  
  
int main(){
  int n, q;
  scanf("%d%d", &n, &q);
  long long k = 0;
  init();
  genperm(k);
  while(q--){
    int type;
    scanf("%d", &type);
    if(type == 1){
      int l, r;
      long long ans = 0;
      scanf("%d%d", &l, &r);
      l--, r--;
      while(n - r <= N_ && l <= r){
        ans += A[N_ - n + r] + (n - N_) + 1;
        r--;
      }
      ans += 1ll * (r - l + 1) * (l + r + 2) / 2;
      printf("%lld\n", ans);
    }
    else{
      int x;
      scanf("%d", &x);
      genperm(k += x);
    }
  }      
  return 0;
}
