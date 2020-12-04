#include<bits/stdc++.h>

using namespace std;

void test_cases(){
  int n;
  scanf("%d", &n);
  long long A[n + 1] = {}, pre[n + 1] = {}, suf[n + 1] = {};
  for(int i = 1; i <= n; i++){
    scanf("%lld", A + i);
    pre[i] = pre[i - 1];
    pre[i] += A[i];
  }    
  for(int i = 1; i <= n; i++){
    map < long long, int > mp;
    for(int j = 0; j <= n - i; j += i){
      long long sum = pre[j + i] - pre[j];
      if(mp.count(sum)){
        puts("YES");
        return;
      }
      mp[sum] = 1;
    }
  }
  puts("NO");
}

int main(){
  int tt = 1; 
  scanf("%d", &tt);
  while(tt--){
    test_cases();
    //puts("");
  }
  return 0;
}
