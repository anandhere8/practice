#include <bits/stdc++.h>

using namespace std;

int main(){
  int m = 6, n, A[(int)1e6], B[m];
  for(int i = 0; i < m; i++){
    scanf("%d", B + i);
  }
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", A + i);
  }
  vector < pair < int, int >> v;
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      v.push_back({-B[i] + A[j], j});
    }
  }
  sort(v.begin(), v.end());
  set < int > st;
  multiset < int > mul;
  int ans = 1e9;
  int j = 0;
  for(int i = 0; i < n * m; i++){
    mul.insert(v[i].second);
    st.insert(v[i].second);
    while((int)st.size() == n){
      ans = min(ans, v[i].first - v[j].first);
      mul.erase(mul.find(v[j].second));
      if(mul.count(v[j].second) == 0){
        st.erase(v[j].second);
      }
      j++;
    }
  }
  printf("%d", ans);
  return 0;
}
