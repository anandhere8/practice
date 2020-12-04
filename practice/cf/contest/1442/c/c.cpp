#include<bits/stdc++.h>

using namespace std;

vector < vector < int >> G;
const int N_ = 2e5 + 20, Mod = 998244353;
bool ok[N_];
set < pair < int, int >> st;
int answer;
int n, dp[N_];
void dfs(int s, int p = -1){
  if(s == n - 1){
    return;
  }
}

int main(){
  int m;
  answer = INT_MAX;
  memset(dp, 0x3F, sizeof dp);
  scanf("%d%d", &n, &m);
  for(int i = 0; i < m; i++){
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    G[u].push_back(v);
    G[v].push_back(u);
    st.insert({u, v});
  }
  dfs(0);
  return 0;
}
    
    
