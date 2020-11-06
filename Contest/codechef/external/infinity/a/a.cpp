#include<bits/stdc++.h>

using namespace std;

void test_cases(){
  int x, y;
  scanf("%d%d", &x, &y);
  int diff = abs(y - x);
  int ans = 0;
  if(x < y){
    if(diff % 2){
      ans = 1;
    }
    else if(diff % 4 == 0) ans = 3;
    else {
      ans = 2;
    }
  }
  else {
    if(diff % 2 == 0){
      ans = 1;
    }
    else ans = 2;
  }
  if(x == y) ans = 0;
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
