#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 10;
int Fac[N],Inv[N];
const int Mod = 1e9 + 7;

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

void test_case(){
	int n;
	cin >> n;
  int m, k;
  // cin >> m >> k;
  m = 3, k = 2;
	vector<int> A(n);
  for(auto i = 0; i < n; ++ i){
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  int ans = 0;
  for(auto i = 0; i < n; ++ i){
    auto it = lower_bound(A.begin(), A.end(), A[i] - k) - A.begin();
    int tmp = i - it;
    tmp = max(0ll, tmp);
    int res = (tmp * (tmp  - 1)) / 2;
    ans += res;
  }
  cout << ans;
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt = 1; 
  pre_process();
  cin >> tt;
  while(tt--){
    test_case();
    cout << endl;
  }
  return 0;
}
