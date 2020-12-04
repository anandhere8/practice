#include<bits/stdc++.h>
#define ll long long
using namespace std;

template <ll MOD=1000000007>
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
    friend istream& operator >> (istream& is, Modular& a) {is >> a.value; return is;}
    friend ostream& operator << (ostream& os, Modular const& a) {return os << a.value;}
    friend bool operator == (Modular const& a, Modular const& b) {return a.value == b.value;}
    friend bool operator != (Modular const& a, Modular const& b) {return a.value != b.value;}
};

const int N = 2005, Mod = 1e9 + 7;
int dp[N][N], r[N][N], down[N][N], diag[N][N];

void test_case(){
  int n, m; cin >> n >> m;
  string A[n];
  for(int i = 0; i < n; i++){
    cin >> A[i];
  }
  dp[0][0] = 1;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(A[i][j] == '#') continue;
      if(j) r[i][j] = r[i][j - 1] + dp[i][j - 1];
      if(i) down[i][j]  = down[i - 1][j] + dp[i - 1][j];
      if(i && j) diag[i][j] = diag[i - 1][j - 1] + dp[i - 1][j - 1];
      dp[i][j] += r[i][j] + down[i][j] + diag[i][j];
    }
  }
  cout << dp[n - 1][m - 1];
}

int32_t main(){
  int tt = 1; 
  //cin >> tt;
  while(tt--){
    test_case();
    cout << endl;
  }
  return 0;
}
