#include<bits/stdc++.h>

using namespace std;

void test_cases(){
  int n;
  scanf("%d", &n);
  int A[n];
  for(int i = 0; i < n; i++){
    scanf("%d", A + i);
  }
  int mx = A[0];
  int x = 0;
  for(int i = 0; i < n - 1; i++) {
    int tmp = A[i];
    mx = min(A[i], mx);
    A[i] -= mx;
    A[i] = max(x, A[i]);
    A[i] = min(A[i], tmp);
    x = A[i];
    mx = tmp - A[i];
  }
  bool ok = true;
  //for(int i = 0; i < n; i++){
    //cerr << A[i] << " ";
  //}
  //cerr << endl;
  for(int i = 1; i < n; i++){
    if(A[i] < A[i - 1]){
      ok = false;
      break;
    }
  }
  if(ok) puts("YES");
  else puts("NO");
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
