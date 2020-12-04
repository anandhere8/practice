#include<bits/stdc++.h>

using namespace std;

int main(){
  int n, ans = 1;
  char s[200000];
  scanf("%d", &n);
  scanf("%s", s);
  for(int i = 1; i < n; i++){
    if(s[i] != s[i - 1]){
      ans++;
    }
  }
  printf("%d\n", min(ans + 2, n));
  return 0;
}
