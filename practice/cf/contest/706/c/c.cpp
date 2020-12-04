#include<bits/stdc++.h>

using namespace std;

int n;
const int nax = 1e6 + 10;
int A[nax], sum;
vector < string > s;
long long dp[nax][2];
bool ok(int i, int j, int a, int b){
  string ss = s[i];
  string tt = s[j];
  if(b) reverse(tt.begin(), tt.end());
  if(a) reverse(ss.begin(), ss.end());
  return ss >= tt;
}

long long solve(int i, int flag){
  if(i >= n)
    return 0;
  
  long long a = 1e16;
  if(dp[i][flag] != -1){
    return dp[i][flag];
  }
  if(ok(i, i - 1, 0, flag)){
    a = solve(i + 1, 0);
  }
  if(ok(i, i - 1, 1, flag)){
    a = min(a, A[i] + solve(i + 1, 1));
  }
  return dp[i][flag] = a;
}
      

void test_cases(){
  scanf("%d", &n);
  for(int i = 0; i <= n; i++){
    dp[i][0] = -1;
    dp[i][1] = -1;
  }
  for(int i = 0; i < n; i++){
    scanf("%d", A + i);
    sum += A[i];
  }
  
  for(int i = 0; i < n; i++){
    string tmp; cin >> tmp;
    s.push_back(tmp);    
  }
  
  long long answer = min(solve(1, 0), A[0] + solve(1, 1));
  //if(answer > sum) answer = -1; 
  printf("%lld", answer);
}

int main(){
  int tt = 1; 
 // scanf("%d", &tt);
  while(tt--){
    test_cases();
    puts("");
  }
  return 0;
}
