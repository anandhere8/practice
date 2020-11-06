#include<bits/stdc++.h>

using namespace std;

void test_cases(){
  int l, r;
  scanf("%d%d", &l, &r);
  long long answer = 0;
  long long len = r - l + 1;
  answer = (len * (len + 1) / 2);
  printf("%lld", answer);
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
