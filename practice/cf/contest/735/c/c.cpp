#include<bits/stdc++.h>

using namespace std;

int main(){
  long long a = 1, b = 1, c = 2, n, ans = 0;
  scanf("%lld", &n);
  while(c <= n)
    a = b,
    b = c,
    c = a + b,
    ans++;
  printf("%lld\n", ans);
  return 0;
}
