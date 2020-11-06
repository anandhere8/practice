#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Mod = 1e9 + 7;
const int N = 2e5 + 10;
long long Fac[N],Inv[N];

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

void test_cases(){
  int n, x, pos;
  scanf("%lld%lld%lld", &n, &x, &pos);
  int l = 0, r = n;
  vector < int > v(n, -1);
  while(l < r){
    int mid = (l + r) / 2;
    if(mid == pos){
      l = mid + 1;
      continue;
    }
    if(mid > pos){
      r = mid;
      v[mid] = 1;
    }
    else{
      l = mid + 1;
      v[mid] = 0;
    }
  }
  //cout << Cnt << endl;
  int more = 0, less = 0, rest = -1;
  for(int i = 0; i < n; i++){
    if(v[i] == 1) more++;
    else if(v[i] == 0) less++;
    else rest++;
  }
  //cout << more << " " << less << " " << rest << endl;
  
  int greater = n - x;
  int lesser = x - 1;
  //cout << greater << " " << lesser << " " << endl;
  long long res = 1;
  //cout << nCr(greater, more) << endl;
  //cout << nCr(lesser, less) << endl;
  //cout << Fac[rest] << endl;
  res *= nCr(greater, more) % Mod * Fac[more] % Mod;
  res %= Mod;
  res *= nCr(lesser, less) % Mod * Fac[less] % Mod;
  res %= Mod;
  res *= Fac[rest];
  res %= Mod;
  printf("%lld", res % Mod);
}

int32_t main(){
  pre_process();
  int tt = 1; 
  //scanf("%d", &tt);
  while(tt--){
    test_cases();
    puts("");
  }
  return 0;
}
