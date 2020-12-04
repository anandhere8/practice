#include<bits/stdc++.h>

#define EB emplace_back
#define int long long
#define mint Modular <Mod>
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define endl '\n'
#define ll long long

using namespace std; 

const int Mod = 1e9 + 7;

template <ll MOD = Mod>
struct Modular {
    ll value;
    static const ll MOD_value = MOD;
    Modular(ll v = 0) {value = v % MOD; if (value < 0) value += MOD;}
    Modular(ll a, ll b) : value(0) {*this += a; *this /= b;}
    Modular& operator += (Modular const& b) {value += b.value; if (value >= MOD) value -= MOD; return *this;}
    Modular& operator -= (Modular const& b) {value -= b.value; if (value < 0) value += MOD;return *this;}
    Modular& operator *= (Modular const& b) {value = (ll)value * b.value % MOD;return *this;}
    friend Modular mexp(Modular a, ll e) {Modular res = 1; while (e) {if (e&1) res *= a; a *= a; e >>= 1;} return res;}
    friend Modular inverse(Modular a) {return mexp(a, MOD - 2);}
    Modular& operator /= (Modular const& b) {return *this *= inverse(b);}
    friend Modular operator + (Modular a, Modular const b) {return a += b;}
    friend Modular operator - (Modular a, Modular const b) {return a -= b;}
    friend Modular operator - (Modular const a) {return 0 - a;}
    friend Modular operator * (Modular a, Modular const b) {return a *= b;}
    friend Modular operator / (Modular a, Modular const b) {return a /= b;}
    friend istream& operator >> (istream& is, Modular& a) {is >> a.value; a.value %= MOD; return is;}
    friend ostream& operator << (ostream& os, Modular const& a) {return os << a.value;}
    friend bool operator == (Modular const& a, Modular const& b) {return a.value == b.value;}
    friend bool operator != (Modular const& a, Modular const& b) {return a.value != b.value;}
};

void test_case(){
  int n, m; cin >> n >> m;
  int A[n + 1];
  for(int i = 1; i <= n; i++){
    cin >> A[i];
  }
  mint dp[n + 2][m + 2];
  memset(dp, 0, sizeof dp);
  if(A[1] == 0){
    for(int i = 1; i <= m; i++)
      dp[1][i] = 1;
  }
  else{
    dp[1][A[1]] = 1;
  }
  for(int i = 2; i <= n; i++){
    int x = A[i];
    if(x) {
      for(int k : {-1, 0, 1}){
        dp[i][x] += dp[i - 1][x + k];
      }
      continue;
    }
    for(int j = 1; j <= m; j++){
      for(int k : {-1, 0, 1}){
        dp[i][j] += dp[i - 1][j + k];
      }
    }
  }  
  
  
  mint res = 0;
  for(int i = 1; i <= m; i++)
    res += dp[n][i];
  cout << res;
}

int32_t main(){
  int tt = 1;
  while(tt--){
    test_case();
  }
  return 0;
}
