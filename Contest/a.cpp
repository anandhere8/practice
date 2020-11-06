#include<bits/stdc++.h>

using namespace std;

void test_cases(){
  int n;
  scanf("%d", &n);
  int A[n];
  for(int i = 0; i < n; i++){
    scanf("%d", A + i);
  }
  long long sum = 0;
  long long ans = 0;
  for(int i = 0; i < n; i += 2){
    sum += A[i];
  }
  ans = max(ans, sum);
  sum = 0;
  for(int i = 1; i < n; i += 2){
    sum += A[i];
  }
  ans = max(ans, sum);
  printf("%lld", ans);
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
