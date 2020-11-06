#include<bits/stdc++.h>
#define int long long
using namespace std;

void test_cases(){
  long long l, r;
  scanf("%lld%lld", &l, &r);
  long long ans = 0;
  if(l % r || l < r){
    ans = l;
  }
  else{
    vector < int > v;
    map < int , int > mp;
    for(int i = 2; i * i <= r; i++){
      if(r % i == 0){
        while(r % i == 0) {
          r /= i;
          mp[i]++;
        }
      }
    }
    if(r > 1) {
      mp[r]++;
    }
    for(auto x : mp){
      long long t = l;
      long long tmp = l;
      int cnt = x.second;
      int cnta = 0;
      while(tmp % x.first == 0){
        cnta++;
        tmp /= x.first;
      }
      cnt = cnta - cnt + 1;
      while(cnt--){
        t /= x.first;
      }
      
      ans = max(ans, t);
    }
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
