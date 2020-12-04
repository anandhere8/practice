#include<bits/stdc++.h>

using namespace std;


int main(){
  int n, k;
  scanf("%d%d", &n, &k);
  int A[n], B[k];
  for(int i = 0; i < n; i++){
    scanf("%d", A + i);
    A[i] -= i;
  }
  int req[n + 1] = {};
  for(int i = 0; i < k; i++){
    scanf("%d", B + i);
    B[i]--;
    req[B[i]] = 1;
  }
  for(int i = 1; i < k; i++){
    if(A[B[i]] < A[B[i - 1]]){
      puts("-1");
      return 0;
    }
  }
  int bad[n + 1] = {}, need = -1;
  for(int i = 0; i < n; i++){
    if(req[i]){
      need = A[i];
    }
    if(need > A[i]){
      bad[i] = 1;
    }
  }
  need = 2e9;
  
  for(int i = n - 1; i >= 0; i--){
    if(req[i]){
      need = A[i];
    }
    if(A[i] > need){
      bad[i] = 1;
    }
  }
  
  multiset < int > mul;
  for(int i = 0; i < n; i++){
    if(!bad[i]){
      mul.insert(A[i]);
      auto it = mul.upper_bound(A[i]);
      if(it != mul.end()){
        mul.erase(it);
      }
    }
  }
  printf("%d", n - (int)mul.size());
  return 0;
}
