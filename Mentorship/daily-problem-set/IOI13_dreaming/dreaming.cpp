#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> SCC;

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
    adj[u].push_back(id), adj[v].push_back(id), edges.push_back({u, v, w});
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

// Requires graph
template<class T, T (*merge)(T, T), T (*identity)()>
struct dfs_forest_base{
  int n;
  vector<T> dist;
  vector<int> pv, pe, order, pos, end, sz, root, depth, min_depth, was;
  dfs_forest_base(int n){ init(n); }
  void init(int n){
    this->n = n;
    pv.assign(n, -1);
    pe.assign(n, -1);
    order.clear();
    pos.assign(n, -1);
    end.assign(n, -1);
    sz.assign(n, 0);
    root.assign(n, -1);
    depth.assign(n, -1);
    min_depth.assign(n, -1);
    dist.assign(n, identity());
    was.assign(n, -1);
    attempt = 0;
  }
  int attempt;
  void dfs(graph<T> &g, int u, bool clear_order = true){
    ++ attempt;
    vector<int> CC;
    depth[u] = 0;
    dist[u] = identity();
    root[u] = u;
    pv[u] = pe[u] = -1;
    if(clear_order) order.clear();
    function<void(int)> recurse = [&](int u){
      CC.emplace_back(u);
      was[u] = attempt;
      pos[u] = (int)order.size();
      order.push_back(u);
      sz[u] = 1;
      min_depth[u] = depth[u];
      for(auto id: g.adj[u]){
        if(id == pe[u] || g.ignore && g.ignore(id)) continue;
        auto &e = g.edges[id];
        int v = e.from ^ e.to ^ u;
        if(was[v] == attempt){
          min_depth[u] = min(min_depth[u], depth[v]);
          continue;
        }
        depth[v] = depth[u] + 1;
        dist[v] = merge(dist[u], e.cost);
        pv[v] = u;
        pe[v] = id;
        root[v] = ~root[u] ? root[u] : v;
        recurse(v);
        sz[u] += sz[v];
        min_depth[u] = min(min_depth[u], min_depth[v]);
      }
      end[u] = (int)order.size();
    };
    recurse(u);
    SCC.emplace_back(CC);
  }
  void dfs_all(graph<T> &g){
    for(auto u = 0; u < n; ++ u) if(!~depth[u]) dfs(u, false);
  }
};
int add_merge(int x, int y){
  return x + y;
}
int add_id(){
  return {};
}
using dfs_forest = dfs_forest_base<int, add_merge, add_id>;

int travelTime(int N, int M, int L, int A[], int B[], int T[]){
  int n = N, m = M, l = L;
  graph<int> g(n);
  for(auto i = 0; i < m; ++ i){
    g.link(A[i], B[i], T[i]);
  }
  dfs_forest dd(n);
  for(auto i = 0; i < n; ++ i){
    if(dd.was[i] == -1){
      dd.dfs(g, i);
    }
  }
  for(auto x : SCC){
    for(auto &xax : x){
      cerr << xax << " ";
    }
    cerr << endl;
  }
  return -1;
}

int main(){
  int n, m, l;
  cin >> n >> m >> l;
  int a[m], b[m], t[m];
  for(auto i = 0; i < m; ++ i){
    cin >> a[i] >> b[i] >> t[i];
  }
  int ans = travelTime(n, m, l, a, b, t);
  cout << ans;
  return 0;
}