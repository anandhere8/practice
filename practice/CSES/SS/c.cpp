#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, x;
  cin >> n >> x;
  vector < int > A(n);
  for(int i = 0; i < n; i++){
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  int l = 0, r = n - 1, res = 0;
  while(l < r){
    if(A[l] + A[r] <= x) l++;
    r--, res++;
  }
  if(l == r){
    res++;
  }
  cout << res;
  return 0;
}