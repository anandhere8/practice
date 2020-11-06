#include<bits/stdc++.h>

using namespace std;

void test_cases(){
  int n;
  scanf("%d", &n);
  int A[n];
  for(int i = 0; i < n; i++){
    scanf("%d", A + i);
  }
  int res = 1;
  int max_ = A[1];
  for(int i = 1; i < n; i++){
    if(max_ > A[i]){
      res++;
      max_ = A[i];
      continue;
    }
    max_ = max(max_, A[i]);
  }
  printf("%d", res);
}

int main(){
  int tt = 1; 
  scanf("%d", &tt);
  while(tt--){
    test_cases();
    puts("");
  }
  return 0;
}
