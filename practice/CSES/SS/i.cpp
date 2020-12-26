#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector < int > A(n);
  for(int i = 0; i < n; i++){
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  long long res = 0ll;
  for(auto &xax : A){
    res += abs(xax - A[n / 2]);
  }
  cout << res;
  return 0;
}