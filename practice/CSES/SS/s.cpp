#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
  int n, m;
  cin >> n;
  vector < int > A(n);
  map<int, int> mp;
  int ans = 0;
  mp[0]++;
  for(int i = 0; i < n; i++){
    cin >> A[i];
    if(i) A[i] += A[i - 1] % n;
    A[i] %= n;
    int rq = ;
    if(mp.count(rq)) ans += mp[rq];
    mp[A[i]]++;
  }
  cout << ans;
  return 0;
}