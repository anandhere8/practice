#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct Z_p{
  using Type = typename decay<decltype(T::value)>::type;
  static vector<Type> mod_inv; 
  constexpr Z_p(): value(){ }
  template<typename U> Z_p(const U &x){ value = normalize(x); }
  template<typename U> static Type normalize(const U &x){
    Type v;
    if(-mod() <= x && x < mod()) v = static_cast<Type>(x);
    else v = static_cast<Type>(x % mod());
    if(v < 0) v += mod();
    return v;
  }
  const Type& operator()() const{ return value; }
  template<typename U> explicit operator U() const{ return static_cast<U>(value); }
  constexpr static Type mod(){ return T::value; }
  Z_p &operator+=(const Z_p &otr){ if((value += otr.value) >= mod()) value -= mod(); return *this; }
  Z_p &operator-=(const Z_p &otr){ if((value -= otr.value) < 0) value += mod(); return *this; }
  template<typename U> Z_p &operator+=(const U &otr){ return *this += Z_p(otr); }
  template<typename U> Z_p &operator-=(const U &otr){ return *this -= Z_p(otr); }
  Z_p &operator++(){ return *this += 1; }
  Z_p &operator--(){ return *this -= 1; }
  Z_p operator++(int){ Z_p result(*this); *this += 1; return result; }
  Z_p operator--(int){ Z_p result(*this); *this -= 1; return result; }
  Z_p operator-() const{ return Z_p(-value); }
  template<typename U = T>
  typename enable_if<is_same<typename Z_p<U>::Type, int>::value, Z_p>::type &operator*=(const Z_p& rhs){
    #ifdef _WIN32
    uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
    uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
    asm(
      "divl %4; \n\t"
      : "=a" (d), "=d" (m)
      : "d" (xh), "a" (xl), "r" (mod())
    );
    value = m;
    #else
    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
    #endif
    return *this;
  }
  template<typename U = T>
  typename enable_if<is_same<typename Z_p<U>::Type, int64_t>::value, Z_p>::type &operator*=(const Z_p &rhs){
    int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }
  template<typename U = T>
  typename enable_if<!is_integral<typename Z_p<U>::Type>::value, Z_p>::type &operator*=(const Z_p &rhs){
    value = normalize(value * rhs.value);
    return *this;
  }
  Z_p operator^(long long e) const{
    Z_p b = *this, res = 1;
    if(e < 0) b = 1 / b, e = -e;
    for(; e; b *= b, e >>= 1) if(e & 1) res *= b;
    return res;
  }
  Z_p &operator^=(const long long &e){ return *this = *this ^ e; }
  Z_p &operator/=(const Z_p &otr){
    Type a = otr.value, m = mod(), u = 0, v = 1;
    if(a < int(mod_inv.size())) return *this *= mod_inv[a];
    while(a){
      Type t = m / a;
      m -= t * a; swap(a, m);
      u -= t * v; swap(u, v);
    }
    assert(m == 1);
    return *this *= u;
  }
  template<typename U> friend const Z_p<U> &abs(const Z_p<U> &v){ return v; }
  Type value;
};
template<typename T> bool operator==(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value == rhs.value; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator==(const Z_p<T>& lhs, U rhs){ return lhs == Z_p<T>(rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator==(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) == rhs; }
template<typename T> bool operator!=(const Z_p<T> &lhs, const Z_p<T> &rhs){ return !(lhs == rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator!=(const Z_p<T> &lhs, U rhs){ return !(lhs == rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator!=(U lhs, const Z_p<T> &rhs){ return !(lhs == rhs); }
template<typename T> bool operator<(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value < rhs.value; }
template<typename T> bool operator>(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value > rhs.value; }
template<typename T> bool operator<=(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value <= rhs.value; }
template<typename T> bool operator>=(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value >= rhs.value; }
template<typename T> Z_p<T> operator+(const Z_p<T> &lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) += rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator+(const Z_p<T> &lhs, U rhs){ return Z_p<T>(lhs) += rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator+(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) += rhs; }
template<typename T> Z_p<T> operator-(const Z_p<T> &lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) -= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator-(const Z_p<T>& lhs, U rhs){ return Z_p<T>(lhs) -= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator-(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) -= rhs; }
template<typename T> Z_p<T> operator*(const Z_p<T> &lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) *= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator*(const Z_p<T>& lhs, U rhs){ return Z_p<T>(lhs) *= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator*(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) *= rhs; }
template<typename T> Z_p<T> operator/(const Z_p<T> &lhs, const Z_p<T> &rhs) { return Z_p<T>(lhs) /= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator/(const Z_p<T>& lhs, U rhs) { return Z_p<T>(lhs) /= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator/(U lhs, const Z_p<T> &rhs) { return Z_p<T>(lhs) /= rhs; }
template<typename T> istream &operator>>(istream &in, Z_p<T> &number){
  typename common_type<typename Z_p<T>::Type, int64_t>::type x;
  in >> x;
  number.value = Z_p<T>::normalize(x);
  return in;
}
template<typename T> ostream &operator<<(ostream &out, const Z_p<T> &number){ return out << number(); }

/*
using ModType = int;
struct VarMod{ static ModType value; };
ModType VarMod::value;
ModType &mod = VarMod::value;
using Zp = Z_p<VarMod>;
*/

constexpr int mod = 1e9 + 7;
//constexpr int mod = (119 << 23) + 1;
using Zp = Z_p<integral_constant<decay<decltype(mod)>::type, mod>>;

template<typename T> vector<typename Z_p<T>::Type> Z_p<T>::mod_inv;
template<typename T = integral_constant<decay<decltype(mod)>::type, mod>>
void precalc_inverse(size_t SZ){
  auto &inv = Z_p<T>::mod_inv;
  if(inv.empty()) inv.assign(2, 1);
  for(; inv.size() <= SZ; ) inv.push_back((mod - 1LL * mod / (int)inv.size() * inv[mod % (int)inv.size()] % mod) % mod);
}

// Requires barrett

struct barrett{
  unsigned int _m;
  unsigned long long im;
  // @param m `1 <= m`
  barrett(unsigned int m): _m(m), im((unsigned long long)(-1) / m + 1){}
  // @return m
  unsigned int umod() const{ return _m; }
  // @param a `0 <= a < m`
  // @param b `0 <= b < m`
  // @return `a * b % m`
  unsigned int mul(unsigned int a, unsigned int b) const{
    unsigned long long z = a;
    z *= b;
    unsigned long long x = (unsigned long long)(((unsigned __int128)(z)*im) >> 64);
    unsigned int v = (unsigned int)(z - x * _m);
    if(_m <= v) v += _m;
    return v;
  }
};

long long pow_mod(long long x, long long n, int m){
  assert(0 <= n && 1 <= m);
  if(m == 1) return 0;
  barrett bt((unsigned int)(m));
  unsigned int r = 1, y = x % m;
  if(y < 0) y += m;
  for(; n; y = bt.mul(y, y), n >>= 1) if(n & 1) r = bt.mul(r, y);
  return r;
}

int main(){
  int n;
  cin >> n;
  vector < Zp > A(n);
  for(int i = 0; i < n; i++){
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  Zp ans = 0;
  for(auto i = 1; i < n; ++ i){
    Zp a = 1;
    a *= (pow_mod(2, i, 1e9 + 7) - 1);
    a *= (pow_mod(2, n - i, 1e9 + 7) - 1);
    a *= (A[i] - A[i - 1]);
    ans += a;
  }
  cout << ans;
  return 0;
}