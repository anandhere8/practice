#include<bits/stdc++.h>
#define int unsigned long long 
using namespace std;

void test_cases(){
  int n, W;
  scanf("%lld%lld", &n, &W);
  vector < pair < int, int >> A ;
  vector < int > res;
  int id = -1;
  bool ok = false;
  for(int i = 0; i < n; i++){
    int x;
    scanf("%lld", &x); 
    if(x > W){
      continue;
    }
    if(2 * x >= W){
      ok = true;
      id = i + 1;
    }
    A.push_back({x, i + 1});
  }
  if(ok){
    printf("%d\n%lld", 1, id);
    return;
  }
  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());
  int sum = 0;
  for(auto [x, y] : A){
    sum += x;
    res.push_back(y);
    if(sum * 2 >= W){
      ok = true;
      break;
    }
  }
  if(!ok){
    printf("%d ", -1);
    return;
  }
  
  printf("%lld\n", (int)res.size());
  for(int i : res){
    printf("%lld ", i);
  }
  assert(sum * 2 >= (W) && sum <= W);
}

int32_t main(){
  int tt = 1; 
  scanf("%lld", &tt);
  while(tt--){
    test_cases();
    puts("");
  }
  return 0;
}
