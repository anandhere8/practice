#include<bits/stdc++.h>

using namespace std;

void test_cases(){
  int n;
  scanf("%d", &n);
  int A[n][n];
  memset(A, 0, sizeof A);
  A[n - 1][0] = 1;
  for(int i = 0; i < n; i++){
    A[i][i] = 1;
    A[i][i + 1] = 1;
  }
  for(int i = 0; i < n; i++, puts("")){
    for(int j = 0; j < n; j++){
      printf("%d ",A[i][j]);
    }
  }
}

int main(){
  int tt = 1; 
  scanf("%d", &tt);
  while(tt--){
    test_cases();
  }
  return 0;
}
