#include<bits/stdc++.h>

#define EB emplace_back
#define int long long
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

const int N = 2e5 + 10;

map < int, int > mp[N];

struct ufds{
  vector < int > par, len;
  ufds(int n){
    par.resize(n);
    len.resize(n, 1);
    for(int i = 0; i < n; i++){
      par[i] = i;
    }
  }    
  
  int find(int u){
    if(u == par[u]){
      return u;
    }
    return par[u] = find(par[u]);
  }
  
  void join(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v){
      return;
    }
    if(len[u] < len[v]){
      swap(u, v);
    }
    len[u] += len[v];
    par[v] = u;
    for(auto x : mp[v]){
      mp[u][x.first] += x.second;
    }
  }
  
  void clear(){
    par.clear(), len.clear();
  }    
};    

void test_case(){
  int n, qq; cin >> n >> qq;
  int A[n];
  for(int i = 0; i < n; i++){
    cin >> A[i];
    A[i]--;
    mp[i][A[i]]++;
  }
  ufds dsu(n);
  while(qq--){
    int type, a, b; cin >> type >> a >> b;
    type--, a--, b--;
    if(!type){
      dsu.join(a, b);
    }
    else{
      cout << mp[dsu.find(a)][b] << endl;
    }
  }
}

int32_t main(){
  IOS;
  int tt = 1; 
  //cin >> tte;
  while(tt--){
    test_case();
    //cout << endl;
  }
  return 0;
}
