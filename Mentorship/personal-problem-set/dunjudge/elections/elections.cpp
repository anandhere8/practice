#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int n, k;
int J[N], G[N];
string s;

int solve(int i, int j){
  if(i > n) return 0;
  int a = solve(i + 1, j);
  int b = 0;
  if(i - j >= k){
    b = solve(i + 1, i) + ((J[i] > J[j]) ? 1 : -1);
  }
  return max(a, b);
}

int main(){
  cin >> n >> k >> s;
  for(int i = 0; i < n; i++){
    if(s[i] == 'J') J[i + 1] = 1;
    else J[i + 1] = -1;
  }
  for(int i = 1; i <= n; i++){
    J[i] += J[i - 1];
  }
  int ans = solve(1, 0);
  cout << ans;
  return 0;
}
