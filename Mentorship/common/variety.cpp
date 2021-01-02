#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, m, w;
  cin >> n >> m >> w;
  vector<int> A(n + 1, 0);
  long long res = 0;
  vector<pair<int, int>> v;
  for(auto i = 0; i < m; ++ i){
    int x, y, z;
    cin >> x >> y >> z;
    v.emplace_back(x, y);
  }
  sort(v.begin(), v.end());
  int r = -1;

  for(auto i = 0; i < m; ++ i){
    if(v[i].second <= r) continue;
    if(v[i].first > r){
      res++;
      if(R <= r)
      r = R;
    }
  }
  return 0;
}