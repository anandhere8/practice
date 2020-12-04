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

vector < vector < pair < int, int >>> G;
vector < int > qq;
void dj(){
  int n = G.size();
  vector < int > d(n, -1e8);
  vector < int > p(n, -1);
  d[0] = 0;
  using pii = pair<int, int>;
  priority_queue<pii> q;
  q.push({0, 0});
  while(!q.empty()){
    int v = q.top().first;
    int d_v = q.top().second;
    q.pop();
    cerr << v << endl;
    if(d_v != d[v]){
      continue;    
    }
    
    for(auto edge : G[v]){
      int to = edge.first;
      int len = edge.second;
      if (min(d[v], len) < d[to]) {
          d[to] = min(d[v], len);
          p[to] = v;
          q.push({to, d[to]});
      }
    }
  }
  for(auto x : qq){
    //cout << d[x] << endl;
  }
}

void test_case(){
  int n, m, q; cin >> n >> m >> q;
  G.resize(n);
  for(int i = 0; i < m; i++){
    int u, v, a;
    cin >> u >> v >> a;
    u--, v--;
    G[u].push_back({v, -a});
    G[v].push_back({u, -a});
  }
  while(q--){
    int x; cin >> x;
    x--;
    qq.push_back(x);
  }
  dj();
}

int32_t main(){
	IOS;
	int tt = 1; 
	// cin >> tt;
	while(tt--){
    test_case();
	}
	return 0;
}
