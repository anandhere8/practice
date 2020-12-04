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
  int n; cin >> n;
  mint dp[n + 1][n + 1];
  memset(dp, 0, sizeof dp);
  string A[n];
  for(int i = 0; i < n; i++) cin >> A[i];
  if(A[0][0] == '.') dp[0][0] = 1;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(A[i][j] == '.'){
        dp[i + 1][j] += dp[i][j];
        dp[i][j + 1] += dp[i][j];
      }
    }
  }
  if(A[n - 1][n - 1] == '*') dp[n - 1][n - 1] = 0;   
  cout << dp[n - 1][n - 1];
}

int32_t main(){
  int tt = 1;
  while(tt--){
    test_case();
  }
  return 0;
}
