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
  int n, T; cin >> n >> T;
  vector < int > A(n);
  for(auto &x : A) cin >> x;
  vector < mint > dp(T + 1, 0);
  dp[0] = 1;
  for(int i = 1; i <= T; i++){
    for(int x : A){
      if(i >= x)
        dp[i] += dp[i - x];
    }
  }
  cout << dp[T];
}

int32_t main(){
  ll tt = 1;
  while(tt--){
    test_case();
  }
  return 0;
}
