#include<bits/stdc++.h>

using namespace std;

int main(){
  long long n, k, l = 1, x;
  scanf("%lld%lld", &n, &k);
  for(int i = 0; i < n; i++){
    scanf("%lld", &x);
    if(l > k) continue;
    x = __gcd(k, x);
    l = lcm(x, l);
  }
  if(l == k){
    puts("Yes");
  }
  else{
    puts("No");
  }
  return 0;
}
