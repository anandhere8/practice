#include <bits/stdc++.h>

using namespace std;

const int N = 2e6;

bool ok[N];
vector<vector<int>> SCC;
vector<int> A;
template<class T>
struct graph{
  struct edge{
    int from, to;
    T cost;
  };
  int n;
  vector<edge> edges;
  vector<vector<int>> adj;
  function<bool(int)> ignore; // edge ignoration rule
  graph(int n): n(n), adj(n), ignore(nullptr){
  }
  int link(int u, int v, T w = 1){ // insert an undirected edge
    int id = (int)edges.size();
    adj[u].push_back(id), edges.push_back({u, v, w});
    return id;
  }
  int orient(int u, int v, T w = 1){ // insert a directed edge
    int id = (int)edges.size();
    adj[u].push_back(id), edges.push_back({u, v, w});
    return id;
  }
  graph reversed() const{ // returns the transpose of the directed graph
    graph res(n);
    for(auto &e: edges){
      res.orient(e.to, e.from, e.cost);
    }
    return res;
  }
};

template<class T>
int solve(graph<T> &g, int s, int p = -1){
  ok[s] = true;
  int res = 0;
  for(auto x : g.adj[s]){
    if(ok[x]) continue;
    res = max(res, A[x] + solve(g, x, s));
  }
  return res;
}
// Requires graph
template<class T> // O(V + E)
void strongly_connected_components(graph<T> &g, auto act_comp){
  int n = g.n, it = 0, ncomps = 0, v;
  vector<int> val(n), comp(n, -1), s, cur;
  function<int(int)> dfs = [&](int u){
    int low = val[u] = ++ it;
    s.push_back(u);
    for(auto e: g.adj[u]){
      int v = u ^ g.edges[e].from ^ g.edges[e].to;
      if(comp[v] < 0) low = min(low, val[v] ?: dfs(v));
    }
    if(low == val[u]){
      do{
        v = s.back(); s.pop_back();
        comp[v] = ncomps;
        cur.push_back(v);
      }while(v != u);
      act_comp(cur); // Process the component
      cur.clear();
      ++ ncomps;
    }
    return val[u] = low;
  };
  for(int u = 0; u < n; ++ u) if(comp[u] < 0) dfs(u);
} // accesses sccs in the reverse topological order

int main(){
  int n, m;
  cin >> n >> m;
  A.resize(n);
  for(int i = 0; i < n; i++){
    cin >> A[i];
  }
  graph <int> g(n);
  for(auto i = 0; i < m; ++ i){
    int u, v;
    cin >> u >> v;
    g.orient(u, v);
  }
  auto f = [&](const vector<int> &component){
     SCC.push_back(component);
  };
  strongly_connected_components(g, f);
  vector < int > imp;
  for(int i = 0; i < SCC.size(); i++){
    if(SCC[i].back() == 0){
      imp = SCC[i];
    }    
  }
  int res = 0;
  for(auto &xax : imp){
    res += A[xax];
    ok[xax] = true;
  }
  int ans = 0;
  for(auto x : imp){
    int tmp = solve(g, x, -1);
    cerr << x << " :" << tmp << endl;
    ans = max(ans, res + tmp);
  }
  cout << ans << endl;
  return 0;
}