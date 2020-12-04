#include<bits/stdc++.h>

using namespace std;

void test_cases(){
  int n;
  scanf("%d", &n);
  int A[n][n];
  int sum = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      scanf("%d", &A[i][j]);
      if(i == j){
        sum += A[i][j];
      }
    }
  }
  int q;
  scanf("%d", &q);
  while(q--){
    int type;
    scanf("%d", &type);
    if(type == 3){
      int ans = sum % 2;
      printf("%d", ans);
    }
    else {
      int x; scanf("%d", &x);
      x--;
      if(A[x][x]){
        sum -= A[x][x];
        A[x][x] = 0;
      }
      else{
        A[x][x] = 1;
        sum += A[x][x];
      }
    }
  }
}

int main(){
  int tt = 1; 
  //scanf("%d", &tt);
  while(tt--){
    test_cases();
    puts("");
  }
  return 0;
}
