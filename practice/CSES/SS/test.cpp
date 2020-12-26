#include <bits/stdc++.h>

using namespace std;

int main(){
  int n = 8;
  vector<pair<int, int>> A(n);
  for(auto i = 0; i < n; ++ i){
    cin >> A[i].first >> A[i].second;
  }
  for(auto i = 0; i < n; ++ i){
    for(auto j = i + 1; j < n; ++ j){
      for(auto k = j + 1; k < n; ++ k){
        bool ok = false;
        vector<pair<int, int>> tmp = {A[i], A[j], A[k]};
        sort(tmp.begin(), tmp.end());
        if(tmp[0].first < tmp[1].first && tmp[1].first < tmp[2].first){
          if(tmp[0].second < tmp[1].second && tmp[1].first < tmp[2].second)
            ok = true;
        }
        if(ok){
          cout << "respectable";
          return 0;
        }
      }
    }
  }
  cout << "ugly";
  return 0;
}