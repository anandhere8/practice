#include<bits/stdc++.h>

using namespace std;

void test_cases(){
  int n;
  scanf("%d", &n);
  int A[n];
  for(int i = 0; i < n; i++){
    scanf("%d", A + i);
  }
  for(int i = 0; i < n; i++){
    vector < int > a, b;
    for(int j = i + 1; j < n; j++){
      a.push_back(A[j]);
    }
    for(int j = i; j >= 0; j--){
      b.push_back(A[j]);
    }
    int g = 1;
    for(int x : a){
      for(int y : b){
        g = max(g, __gcd(x, y));
        if(g > 1) break;
      }
      if(g > 1) break;
    }
    if(g == 1){
      printf("%d ", i + 1);
      return;
    } 
  }
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
