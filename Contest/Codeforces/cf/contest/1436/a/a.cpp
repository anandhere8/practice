#include<bits/stdc++.h>

using namespace std;

void test_cases(){
  int n, m;
  scanf("%d%d", &n, &m);
  int A[n];
  int sum = 0;
  for(int i = 0; i < n; i++){
    scanf("%d", A + i);
    sum += A[i];
  }
  if(m == sum){
    puts("YES");
  }
  else{
    puts("NO");
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
