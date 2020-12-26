#include <bits/stdc++.h>

using namespace std;

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
  graph(int n): n(n), adj(n){ }
  int link(int u, int v, T w = 1){ // insert an undirected edge
    int id = (int)edges.size();
    adj[u].push_back(id), adj[v].push_back(id), edges.push_back({u, v, w});
    return id;
  }
  int orient(int u, int v, T w = 1){ // insert a directed edge
    int id = (int)edges.size();
    adj[u].push_back(id), edges.push_back({u, v, w});
    return id;
  }
  graph transposed() const{ // the transpose of the directed graph
    graph res(n);
    for(auto &e: edges) res.orient(e.to, e.from, e.cost);
    res.ignore = ignore;
    return res;
  }
  int degree(int u){ // the degree (outdegree if directed) of u (without the ignoration rule)
    return (int)adj[u].size();
  }
};
// Requires graph
template<class T> // O(V + E)
void strongly_connected_components(const graph<T> &g, auto act_comp){
  int n = g.n, it = 0, ncomps = 0, v;
  vector<int> val(n), comp(n, -1), s, cur;
  function<int(int)> dfs = [&](int u){
    int low = val[u] = ++ it;
    s.push_back(u);
    for(auto id: g.adj[u]){
      if(g.ignore && g.ignore(id)) continue;
      int v = u ^ g.edges[id].from ^ g.edges[id].to;
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
  
  auto testcase = [&](){
    int n, m;
    cin >> n >> m;
    int res = 0;
    graph<int> g(n);
    for(auto i = 0; i < m; ++ i){
      int a, b;
      cin >> a >> b;
      a--, b--;
      if(a == b) continue;
      res++;
      g.orient(a, b);
    }

    auto foo = [&](auto &v){
      res += ((int)v.size() > 1);
    };
    strongly_connected_components(g, foo);
    cout << res;
  };

  int tt = 1;
  cin >> tt;
  while(tt--){
    testcase();
    cout << endl;
  }
  return 0;
}