#include<bits/stdc++.h>

using namespace std;

void test_cases(){
  int a, b, c, d;
  scanf("%d%d%d%d", &a, &b, &c, &d);
  int ans = max(a + b, c + d);
  printf("%d", ans);
}

int main(){
  int tt = 1; 
  scanf("%d", &tt);
  while(tt--){
    test_cases();
    puts("");
  }
  return 0;
}
