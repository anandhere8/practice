#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  vector < int > A(n);
  
  for(int i = 0; i < n; i++){
    cin >> A[i];
    // mp[A[i]] = i;
  }
  map<int, pair<int, int>> mp;
  for(auto i = 0; i < n; ++ i){
    for(auto j = i + 1; j < n; ++ j){
      int req = m - A[i] - A[j];
      if(mp.count(req)){
        cout << i + 1 << " " << j + 1 << " " << mp[req].first + 1 << " " << mp[req].second + 1 << endl;
        return 0;
      }
    }
    for(auto j = i - 1; j >= 0; -- j){
      mp[A[i] + A[j]] = {i, j};
    }
  }
  cout << "IMPOSSIBLE";
  return 0;
}