#include<bits/stdc++.h>

using namespace std;

void test_cases(){
  int n;
  scanf("%d", &n);
  long long answer = LLONG_MAX;
  pair < long long, long long > A[n + 1];
  for(int i = 0; i < n; i++){
    scanf("%lld", &A[i].first);
  }
  for(int i = 0; i < n; i++){
    scanf("%lld", &A[i].second);
  }
  A[n].first = A[n].second = 0;
  sort(A, A + n);
  reverse(A, A + n);
  long long sum = 0;
  for(int i = 0; i <= n; i++){
    answer = min(answer, max(A[i].first, sum));
    sum += A[i].second;
  }
  printf("%lld", answer);
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
