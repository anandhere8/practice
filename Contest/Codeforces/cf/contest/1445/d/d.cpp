#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
long long Fac[N],Inv[N];
const int Mod = 998244353;

int power(int a, int b){
  if(b == 0) return 1;
  long long ans = power(a, b / 2) % Mod;
  ans = (ans % Mod * ans % Mod) % Mod;
  if(b % 2) ans = (ans % Mod * a % Mod) % Mod;
  return ans % Mod;
}

int Inverse_Mod(int x){
  return power(x, Mod - 2) % Mod;
}

void pre_process(){
  Fac[0] = 1;
  for(int i = 1; i < N; i++) Fac[i] = (Fac[i - 1] % Mod * i % Mod) % Mod;
  
  Inv[N - 1] = Inverse_Mod(Fac[N - 1]) % Mod;
  for(int i = N - 2; i >= 0; i--){
    Inv[i] = (Inv[i + 1] % Mod * (i + 1) % Mod) % Mod;
  }
}

int nCr(int a, int b){
  if(b < 0 || a < b || a < 0) return 0;
  int ans = (Fac[a] % Mod * 1ll * Inv[b] % Mod) % Mod;
  ans = (ans % Mod * Inv[a - b] % Mod) % Mod;
  return ans;
}

void test_cases(){
  pre_process();
  int n;
  scanf("%d", &n);
  n *= 2;
  int A[n];
  for(int i = 0; i < n; i++){
    scanf("%d", A + i);
  }
  long long answer = 0;
  sort(A, A + n);
  int l = 0, r = n - 1;
  while(l < r){
    answer += A[r] - A[l];
    answer %= Mod;
    l++, r--;
  }
  //cerr << nCr(n, n / 2) << endl;
  answer = (answer * nCr(n, n / 2)) % Mod;
  printf("%lld", answer);
}

int main(){
  int tt = 1; 
  //scanf("%d", &tt);
  while(tt--){
    test_cases();
    puts("");
  }
  return 0;
}
