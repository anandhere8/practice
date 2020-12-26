#include<bits/stdc++.h>

#define EB emplace_back
#define int long long
#define F first
#define S second
#define N 500005
#define all(x) x.begin(),x.end()
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;



vector< vector < int >> G;
vector < int > ok, dist;
vector<int> cycle;
vector<int> component;
bool f;
#define adj G
#define visited ok

void dfs(int source, int parent = -1)
{
  visited[source] = true;
  component.push_back(source);
  for(int u : adj[source])
  {
    if(u == parent)
    {
      continue;
    }
    if(visited[u])
    {
      // cycle
      if(cycle.empty())
      {
        for(int i = (int) component.size() - 1; i >= 0; i--)
        {
          cycle.push_back(component[i]);
          if(component[i] == u)
          {
            break;
          }
        }
      }
      continue;
    }
    dfs(u, source);
  }
  component.pop_back();
}

int cnt;

void rec(int s, int p = -1){
  cnt++;
  dist[s] = 1;
  for(auto x : G[s]){
    if(!dist[x]){
      rec(x, s);
    }
  }
}

void init(int n){
  G.clear();
  component.clear();
  ok.clear();
  dist.clear();
  f = false;
  cycle.clear();
  G.resize(n + 4);
  ok.resize(n + 4, 0);
  dist.resize(n + 4, 0);
}

void test_cases(){
  int n, m;
  cin >> n;
  m = n;
  init(n);
  for(int i = 0; i < m; i++){
    int a, b; 
    cin >> a >> b;
    a--, b--;
    G[a].EB(b);
    G[b].EB(a);
  }
  int root = 0;
  dfs(root);
  vector<int> dfs_tree = cycle;
  
  for(auto x : dfs_tree){
    dist[x] = 1;
  }
  int ans = n * (n - 1);
  for(auto x : dfs_tree){
    cnt = 0;
    rec(x);
    ans -= (cnt * (cnt - 1)) / 2;
  }
  cout << ans;
}

int32_t main(){
  IOS;
  int tt = 1; 
  cin >> tt;
  while(tt--){
    test_cases();
    cout << endl;
  }
  return 0;
}
