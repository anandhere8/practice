#include <bits/stdc++.h>

using namespace std;

int cmin(int a, int b){
  return min(a, b);
}

int main(){
  int n;
  cin >> n;
  vector<pair<int, int>> Ex, Ey, Nx, Ny;
  vector<int> res(n);
  for(int i = 0; i < n; i++){
    char c;
    int x, y;
    cin >> c >> x >> y;
    if(c == 'N'){
      Nx.emplace_back(x, i);
      Ny.emplace_back(y, i);
    }
    else{
      Ex.emplace_back(x, i);
      Ey.emplace_back(y, i);
    }
  }
  int ans = 0;
  for(int i = 0; i < (int)Ex.size(); i++){
    int x1 = Ex[i].first, y1 = Ey[i].first;
    int min = 1e9 + 9;
    for(int j = 0; j < (int)Nx.size(); j++){
      int x2 = Nx[j].first, y2 = Ny[j].first;
      if(x2 <= x1) continue;
      if(y2 >= y1) continue;
      int tmp = 1e9 + 10;
      if(y1 - y2 < x2 - x1){
        tmp = cmin(tmp, x2 - x1);
      }
      if(min > tmp) min = tmp;
    }
    res[Ex[i].second] = min;
    cerr << x1 << " " << y1 << " : " << min << endl; 
  }
  return 0;
}