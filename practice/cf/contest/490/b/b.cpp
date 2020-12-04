#include<bits/stdc++.h>

using namespace std;

int main(){
  vector < pair < int, int >> v;
  int A[(int)1e6 + 10], cnt[(int)1e6 + 10] = {};
  int n, x, y;
  vector < int > res(2);
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d%d", &x, &y);
    if(x == 0) {
      res[1] = y;
    }
    cnt[x]++, cnt[y]++;
    A[x] = y;
    v.push_back({x, y});
  }
  for(auto [i, j] : v){
    if(!i) continue;
    if(cnt[i] == 1){
      res[0] = i;
      break;
    }
  }
  for(int i = 0; i < n - 2; i++){
    res.push_back(A[res[i]]);
    printf("%d ", res[i]);
  }
  printf("%d %d", res[n - 2], res[n - 1]);
  return 0;
}
