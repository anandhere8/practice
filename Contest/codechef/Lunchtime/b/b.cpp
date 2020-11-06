#include<bits/stdc++.h>
#define int long long
using namespace std;

void test_cases(){
  int n;
  scanf("%lld", &n);
  int A[n + 1];
  map < int, int > mp;
  for(int i = 1; i <= n; i++){
    scanf("%lld", A + i);
  }
  
  for(int i = 1; i <= n; i++){
    int x = A[i];
    for(int j = 2; j * j <= x; j++){
      if(x % j == 0){
        mp[j] = max(i, mp[j]);
        while(x % j == 0){
          x /= j;
        }         
      }
    }
    if(x > 1) mp[x] = max(mp[x], i);
  }
  int ans = 1;
  for(int i = 1; i <= n; i++){
    int x = A[i];
    for(int j = 2; j * j <= x; j++){
      if(x % j == 0){
        ans = max(ans, mp[j]);
        while(x % j == 0) x /= j;
      }
    }
    if(x > 1){
      ans = max(ans, mp[x]);
    }
    if(ans == i) break;
  } 
  printf("%lld", ans);
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
