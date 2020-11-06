#include<bits/stdc++.h>

using namespace std;

int solve(string s, char c){
  int Cnt = 1, res = 0;
  int n = s.size();
  for(int i = 1; i < n; i++){
    if(s[i] == s[i - 1] && s[i] == c){
      Cnt++;
    }
    else{
      res += Cnt - 1;
      Cnt = 1;
    }
  }
  res += Cnt - 1;
  return res;
}

void test_cases(){
  int n;
  scanf("%d", &n);
  char s[n];
  scanf("%s", s);
  int res = solve(s, '0');
  res = max(res, solve(s, '1'));
  printf("%d", res);
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
