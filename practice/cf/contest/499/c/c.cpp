#include<bits/stdc++.h>

using namespace std;

int sign(long long x){
  if(x < 0){
    return 1;
  }
  return 2;
}

int main(){
  int x1, x2, y1, y2, n, a, b, c, answer = 0;
  long long val1, val2;
  scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &n);
  for(int i = 0; i < n; i++){
    scanf("%d%d%d", &a, &b, &c);
    val1 = 1ll * a * x1 + 1ll * b * y1 + c;
    val2 = 1ll * a * x2 + 1ll * b * y2 + c;
    if(sign(val1) != sign(val2)){
      answer++;
    }
  }
  printf("%d", answer);
  return 0;
}
