#include<bits/stdc++.h>

using namespace std;
const int N = 1e6 + 10;
long long ans, res[N];
int A[N], B[N], len[N], par[N];
vector < long long > v;
bool ok[N];

int find(int u){
  return par[u] == u ? u : par[u] = find(par[u]);
}

void init(int n){
  for(int i = 0; i <= n + 2; i++){
    par[i] = i, len[i] = 1;
  }
}

void join(int a, int b){
  if(!ok[a] || !ok[b]){
    return;
  }
  a = find(a), b = find(b);
  ans = res[a] + res[b];
  if(len[a] < len[b]) swap(a, b);
  par[b] = a;
  res[a] = ans;
}

void check(int u){
  //cerr << u << endl;
  ok[u] = true;
  res[u] = A[u];
  ans = res[u];
  join(u, u + 1);
  join(u, u - 1);
  v.push_back(max(v.back(), ans));
}

int main(){
  int n;
  scanf("%d", &n);
  int m = n;
  init(n);
  for(int i = 1; i <= n; i++){
    scanf("%d", A + i);
  }
  for(int j = 0; j < m; j++){
    scanf("%d", B + j);
  }
  reverse(B, B + m);
  v.push_back(0);
  for(int i = 0; i < m - 1; i++){
    check(B[i]);
  }
  reverse(v.begin(), v.end());
  for(long long x : v){
    printf("%lld\n", x);
  }
  return 0;
}
