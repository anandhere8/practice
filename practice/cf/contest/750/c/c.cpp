#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, m, i = 0;
  scanf("%d%d", &n, &m);
  int mp[n + 1] = {}, mpr[n + 1] = {}, tmp[n + 1] = {};
  int answer = 0;
  vector < int > v;
  while(m--){
    int type, x;
    scanf("%d%d", &type, &x);
    if(type == 1){
      mp[x]++;
      v.push_back(x);
      answer++;
    }
    else if(type == 2){
      answer -= mp[x];
      mpr[x] += mp[x];
      mp[x] = 0;
    }
    else{
      while(x > i){
        tmp[v[i]]++;
        if(tmp[v[i]] > mpr[v[i]]){
          mpr[v[i]]++;
          answer--, mp[v[i]]--;                          
        }
        i++;
      }
    }
    printf("%d\n", answer);
  }
  return 0;
}
      
