#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 10;
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
	int ans = (Fac[a] % Mod * Inv[b] % Mod) % Mod;
	ans = (ans % Mod * Inv[a - b] % Mod) % Mod;
	return ans;
}
	
int main(){
	pre_process();
	int n; cin >> n;
  n *= 2;
  int A[n];
  long long ans = 0;
  for(int i = 0; i < n; i++) cin >> A[i];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      ans += abs(A[i] - A[j])  * Fac[n / 2 - 1] ;
      ans %= Mod;
    }
  }
  cout << ans;
	return 0;
}
