#include <bits/stdc++.h>

using namespace std;

long long nC3(int x){
  return 1ll * x * (x - 1) * (x - 2) / 6;
}

const int nax = 1e6 + 10;
int A[nax];

int main(){
  int n, x;
  scanf("%d", &n);
  long long mul[nax] = {};
  for(int i = 0; i < n; i++){
    scanf("%d", &x);
    ++A[x];
  }
  for(int i = 1; i < nax; i++){
    for(int j = i; j < nax; j += i){
      mul[i] += A[j];
    }
    mul[i] = nC3(mul[i]);
  }
  
  for(int i = nax - 1; i; i--){
    for(int j = i + i; j < nax; j += i){
      mul[i] -= mul[j];
    }
  }
  printf("%lld", mul[1]);
  return 0;
}
