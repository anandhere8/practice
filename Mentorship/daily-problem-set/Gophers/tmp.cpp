#include <bits/stdc++.h>

using namespace std;

int main(){
  int tt;
  scanf("%d", &tt);
  while(tt--){
    char s[500];
    scanf("%s", s);
    int sum = 0, even = 0;
    bool ok = false;
    for(int i = 0; i < strlen(s); i++){
      char x = s[i];
      if(x % 2 == 0) even++;
      sum += (x - '0');
      sum %= 3;
      if(x == '0') ok = true;
    }
    if(ok && sum % 3 == 0 && even > 1){
      puts("red");
    }
    else puts("cyan");
  }
  return 0;
}
