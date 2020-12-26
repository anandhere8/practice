#include <bits/stdc++.h>
#define ll __int128
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  vector <ll> A(n), B(m);
  for(int i = 0; i < n; i++){
    long long x;
    cin >> x;
    A[i] = x;
  }
  for(int i = 0; i < m; i++){
    long long x;
    cin >> x;
    B[i] = x;
  }
  ll ans = 0;
  for(auto  i =  0;  i < m;  i++){
    ll g = 0;
    for(auto  j =  0; j < n; j++){
      g = __gcd(g, B[i] + A[j]);
    }
    long long gd = g;
    cout << gd << " ";
  }
  return 0;
}