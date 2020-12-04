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
vector < int > ok, dist, cat;
int m;
void dfs(int s,int p = -1){
	ok[s] = 1;
	for(auto x : G[s]){
		if(!ok[x]){
      dist[x] = 1 + dist[s];
      if(cat[x] || cat[s] > m){
        cat[x] = 1 + cat[s];
      }
			dfs(x,s);
		}
	}
}

void init(int n){
  G.clear();
  ok.clear();
  G.resize(n + 4);
  ok.resize(n + 4, 0);
  cat.resize(n + 4, 0);
  dist.resize(n + 4, 0);
}

void test_cases(){
  int n;
  cin >> n >> m;
  init(n);
  for(int i = 0; i < n; i++) cin >> cat[i];
  for(int i = 0; i < n - 1; i++){
    int a, b; 
    cin >> a >> b;
    a--, b--;
    G[a].EB(b);
    G[b].EB(a);
  }
  int root = 0;
  dfs(root);
  int res = 0;
  for(int i = 0; i < n; i++){
    if((int)G[i].size() == 1){
      res++;
      if(cat[i] > m) res--;
    }
  }
  cout << res;
}

int32_t main(){
	IOS;
	int tt = 1; 
	//cin >> tt;
	while(tt--){
		test_cases();
	}
	return 0;
}
