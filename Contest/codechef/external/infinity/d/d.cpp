#include<bits/stdc++.h>

using namespace std;

void first(){
  puts("Walter");
}

void second(){
  puts("Jesse");
}


void test_cases(){
  int n;
  int odd = 0, even = 0;
  int k;
  scanf("%d%d", &n, &k);
  int x;
  for(int i = 0; i < n; i++){
    scanf("%d", &x);
    if(x % 2) odd++;
    else even++;
  }
  if(k % 2){
    if(odd > k / 2){
      first();
    }
    else{
      second();
    }
  }
  else{
    if(odd <= k / 2){
      second();
    }
    else{
      if(odd % 2 == even % 2) {
        second();
      }
      else first();
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
