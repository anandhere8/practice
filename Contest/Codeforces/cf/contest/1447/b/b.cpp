#include<bits/stdc++.h>

using namespace std;

void test_cases(){
  int n, m;
  scanf("%d%d", &n, &m);
  vector < int > neg, pos;
  int sum = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      int x;
      scanf("%d", &x);
      if(x > 0){
        pos.push_back(x);
      }
      else{
        neg.push_back(x);
      }
      sum += abs(x);
    }
  }
  sort(neg.begin(), neg.end(), greater < int > ());
  sort(pos.begin(), pos.end());
  if((int)neg.size() % 2){
    int val = neg[0];
    if((int)pos.size()){
      if(pos[0] < abs(neg[0])){
        val = pos[0];
      }
    }
    sum -= 2 * abs(val);
  }
  printf("%d ", sum);
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
