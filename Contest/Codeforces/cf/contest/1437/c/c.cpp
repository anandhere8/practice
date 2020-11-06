#include<bits/stdc++.h>

using namespace std;
const int nax = 450;
int n;
int dp[nax][nax], A[nax];
void test_cases(){
  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    scanf("%d", A + i);
  }
  sort(A + 1, A + n + 1);
  for(int i = 1; i <= n; i++){
    for(int tim = 0; tim < n + n; tim++){
        if(tim < i){
          dp[i][tim] = 1e9;
          continue;
        }
        dp[i][tim] = min(dp[i][tim - 1], abs(A[i] - tim) + dp[i - 1][tim - 1]);
    }
  } 
  printf("%d", dp[n][n + n - 1]);
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
