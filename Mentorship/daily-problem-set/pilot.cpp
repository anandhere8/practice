#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 10;
int par[N], len[N], n, m,  j, i;
long long res[N], ans;
bool ok[N];
array < int, 2 > A[N], B[N];

long long foo(int x){
  return (1ll * x * (x + 1)) / 2;
}

int find(int u){
  if(u == par[u]){
    return u;
  }
  return par[u] = find(par[u]);
}

void join(int a, int b){
  if(!ok[a] || !ok[b]){
    return;
  }
  a = find(a), b = find(b);
  ans -= foo(len[a]);
  ans -= foo(len[b]);
  if(len[a] < len[b]) swap(a, b);
  len[a] += len[b];
  par[b] = par[a];
  ans += foo(len[a]);
}

void refresh(int v){
  ok[v] = true;
  ans += foo(len[v]);
  join(v, v + 1);
  join(v, v - 1);
}

int main(){
  scanf("%d%d", &n, &m);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i][0]);
    A[i][1] = i + 1;
    par[i] = i, len[i] = 1;
  }
  par[n] = n, len[n] = 1;
  for(i = 0; i < m; i++){
    scanf("%d", &B[i][0]);
    B[i][1] = i;
  }
  sort(A, A + n), sort(B, B + m);
  j = 0;
  for(i = 0; i < m; i++){
    while(j < n && A[j][0] <= B[i][0]){
      refresh(A[j][1]);
      j++;
    }
    res[B[i][1]] = ans;
  }
  for(i = 0; i < m; i++){
    printf("%lld\n", res[i]);
  }
  return 0;
}
