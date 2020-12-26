#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  int x;
  cin >> x;
  vector < int > A(n), B(m);
  for(int i = 0; i < n; i++){
    cin >> A[i];
    A[i] -= x;
  }
  for(int i = 0; i < m; i++){
    cin >> B[i];
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  int res = 0, i = 0, j = 0;
  while(i < n && j < m){
    while(B[j] < A[i] && j < m) j++;
    if(j < m && B[j] >= A[i] && B[j] <= A[i] + 2 * x) {
      res++;
      i++;
      j++;
    }
    while(A[i] + 2 * x < B[j] && i < n) i++;
    if(i < n && B[j] >= A[i] && B[j] <= A[i] + 2 * x){
      res++;
      i++, j++;
    }
  }
  cout << res;
  return 0;
}