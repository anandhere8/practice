#include<bits/stdc++.h>

using namespace std;

void test_cases(){
  int n, m;
  scanf("%d%d", &n, &m);
  int A[n], B[n];
  for(int i = 0; i < n; i++){
    scanf("%d", A + i);
  }
  for(int i = 0; i < n; i++){
    scanf("%d", B + i);
  }
  sort(A, A + n);
  sort(B, B + n, greater < int > ());
  bool ok = true;
  for(int i = 0; i < n; i++){
    if(A[i] + B[i] > m){
      ok = false;
      break;
    }
  }
  if(ok) puts("Yes");
  else puts("No");
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
