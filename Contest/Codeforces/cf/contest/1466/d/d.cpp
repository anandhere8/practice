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

void dfs(int s,int p = -1){
  ok[s] = 1;
  for(auto x : G[s]){
    if(!ok[x]){
      dfs(x,s);
      dist[x] = 1 + dist[s];
    }
  }
}

void init(int n){
  G.clear();
  ok.clear();
  G.resize(n + 4);
  ok.resize(n + 4, 0);
  dist.resize(n + 4, 0);
}

void test_cases(){
  int n, m;
  cin >> n;
  init(n);
  // int n;
  // cin >> n;
  vector<int> A(n);
  vector<array<int, 2>> deg(n);
  int sum = 0;
  for(int i = 0; i < n; i++){
    cin >> A[i];
    sum += A[i];
    deg[i][0] = A[i];
  }
  for(auto i = 0; i < n - 1; ++ i){
    int x, y;
    cin >> x >> y;
    x--, y--;
    deg[x][1]++, deg[y][1]++;
  }
  sort(deg.begin(), deg.end());
  reverse(deg.begin(), deg.end());
  cout << sum << " ";
  int cnt = n - 1;
  for(auto i = 0; i < n && cnt;){
    if(deg[i][1] == 1){
      ++ i;
      continue;
    }
    else{
      cnt--;
      sum += deg[i][0];
      deg[i][1]--;
      cout << sum << " ";
    }
  }
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
