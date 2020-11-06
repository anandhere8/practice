#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 10;
vector < vector < int >> G;
long long dp[N], leaf[N], A[N], tot[N];

void dfs(int s){
  if((int)G[s].size() == 0){
    leaf[s] = 1;
  }
  tot[s] = A[s];
  for(int i : G[s]){
    dfs(i);
    leaf[s] += leaf[i];
    A[s] += A[i];
    dp[s] = max(dp[s], dp[i]);
  }
  dp[s] = max(dp[s], (A[s] + leaf[s] - 1) / leaf[s]);
}
    

void test_cases(){
  int n;
  scanf("%d", &n);
  G.resize(n);
  for(int i = 0; i < n - 1; i++){
    int x;
    scanf("%d", &x);
    x--;
    G[x].push_back(i + 1);
  }
  for(int i = 0; i < n; i++){
    scanf("%lld", A + i);
  }
  dfs(0);
  printf("%lld", dp[0]);
}

int main(){
  int tt = 1; 
  //scanf("%d", &tt);
  while(tt--){
    test_cases();
    //puts("");
  }
  return 0;
}
