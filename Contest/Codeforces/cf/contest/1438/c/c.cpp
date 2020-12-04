#include<bits/stdc++.h>

using namespace std;

void test_cases(){
  int n, m;
  scanf("%d%d", &n, &m);
  int A[n][m];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      scanf("%d", &A[i][j]);
      if((i + j) % 2 == 0){
        if(A[i][j] % 2){
          A[i][j]++;
        }
      }
      else{
        if(A[i][j] % 2 == 0){
          A[i][j]++;
        }
      }
      printf("%d ", A[i][j]);
    }
    puts("");
  }
}

int main(){
  int tt = 1; 
  scanf("%d", &tt);
  while(tt--){
    test_cases();
    //puts("");
  }
  return 0;
}
