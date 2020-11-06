#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int n, notes[N], A[6];
int dp[N];
int solve(int i, int j, int min_, int max_){
   if(i == n){
     return max_ - min_;
   }
   int ans = 1e15;
   if(dp[i] != -1) return dp[i];
   for(int x = 0; x < 6; x++){
     int Tmin_ = min(min_, notes[i] - A[x]);
     int Tmax_ = max(max_, notes[i] - A[x]);
     int res = solve(i + 1, x, Tmin_, Tmax_);
     ans = min(ans, res);
   }
   return dp[i] = ans;
}

void test_cases(){
  int m = 6;
  memset(dp, -1, sizeof dp);
  for(int i = 0; i < m; i++){
    scanf("%lld", A + i);
  }
  scanf("%lld", &n);
  for(int i = 0; i < n; i++){
    scanf("%lld", &notes[i]);
  }
  int answer = 1e15;
  for(int i = 0; i < m; i++){
    answer = min(answer, solve(1, i, notes[0] - A[i], notes[0] - A[i]));
  }
  //answer = solve(0, i, 0, 0);
  printf("%lld", answer);
}

int32_t main(){
  int tt = 1; 
  //scanf("%d", &tt);
  while(tt--){
    test_cases();
    puts("");
  }
  return 0;
}
