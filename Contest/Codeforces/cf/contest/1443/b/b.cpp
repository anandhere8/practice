#include<bits/stdc++.h>

using namespace std;

const int nax = 2e5;
char str[nax];
int n;
int a = 0, b = 0;
int dp[nax][2];
int solve(int i, int flag){
  if(i == n){
    return 0;
  }
  int ans = 1e9;
  if(dp[i][flag] != -1){
    return dp[i][flag];
  }
  if(str[i] == '1'){
    ans = solve(i + 1, 1);
    if(!flag){
      ans += a;
    }
    return dp[i][flag] = ans;
  }
  int nas = ans;
  if(flag) ans = b + solve(i + 1, 1);
  else ans = a + b + solve(i + 1, 1);
  nas = solve(i + 1, 0);
  return dp[i][flag] = min(ans, nas);
}

void test_cases(){
  //int a, b;
  scanf("%d%d", &a, &b);
  int answer = a;
  scanf("%s", str);
  n = strlen(str);
  for(int i = 0; i <= n; i++){
    dp[i][0] = -1;
    dp[i][1] = -1;
  }
  answer = solve(0, str[0] - '0');
  if(str[0] - '0') answer += a;
  printf("%d", answer);
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
