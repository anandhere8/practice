#include<bits/stdc++.h>
#define int long long
using namespace std;

void test_case(){
	int n, k;
  cin >> n >> k;
  vector<pair<int, int>> v(n);
  for(auto i = 0; i < n; ++ i){
    cin >> v[i].first >> v[i].second;
  }
  sort(v.begin(), v.end());
  bool ok = true;
  int dist = 1e9;
  for(int i = 0; i < n; i++){
    int sum = 0;
    for(int j = 0; j < n; j++){
      int tmp = abs(v[i].first - v[j].first) + abs(v[j].second - v[i].second);
      sum = max(tmp, sum);
    }
    dist = min(dist, sum);
  }
  if(dist <= k){
    cout << 1;
    //cerr << dist << endl;
  }
  else cout << -1;
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt = 1; 
  cin >> tt;
  while(tt--){
    test_case();
    cout << endl;
  }
  return 0;
}
