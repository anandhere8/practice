#include <bits/stdc++.h>

using namespace std;

int main(){
  long long n, m;
  cin >> n >> m;
  vector<long long> A(n);
  for(int i = 0; i < n; i++){
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  auto ok = [&](long long T){
    long long sum = 0;
    for(long long x : A){
      sum += T / x;
      if(sum >= m){
        return true;
      }
    }
    return false;
  };
  long long l = 1, r = 1e18, ans = 1e18;
  while(l <= r){
    long long mid = l + (r - l) / 2;
    if(ok(mid)){
      ans = mid;
      r = mid - 1;;
    }
    else
      l = mid + 1;
  }
  cout << ans;
  return 0;
}