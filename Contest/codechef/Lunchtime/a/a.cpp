#include<bits/stdc++.h>

using namespace std;

void test_cases(){
  int n, q; 
  scanf("%d", &n);
  scanf("%d", &q);
  int A[n + 1];
  long long sum = 1;
  for(int i = 0; i < n; i++){
    scanf("%d", A + i);
  }
  for(int i = 1; i < n; i++){
    if(A[i] != A[i - 1]){
      sum++;
    }
  }
  while(q--){
    int x, val;
    scanf("%d%d", &x, &val);
    x--;
    int stb, sta;
    if(A[x] == val){
    }
    else{
      sta = 0, stb = 0;
      if(x > 0 && A[x] != A[x - 1]) stb++;
      if(x < n && A[x] != A[x + 1]) stb++;
      A[x] = val;
      if(x > 0 && A[x] != A[x - 1]) sta++;
      if(x < n && A[x] != A[x + 1]) sta++;
      sum += sta - stb;
    }         
    printf("%lld\n", sum);
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
