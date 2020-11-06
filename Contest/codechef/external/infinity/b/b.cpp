#include<bits/stdc++.h>

using namespace std;

void test_cases(){
  int n;
  scanf("%d", &n);
  int A[n];
  vector < pair < int, int >> v(n);
  for(int i = 0; i < n; i++){
    scanf("%d", A + i);
    v[i].first  = A[i];
    v[i].second = i + 1;
  }
  sort(v.begin(), v.end());
  int id = 0;
  for(int i = 0; i < n; i++){
    int ans = A[i];
    int x = v[id].first + abs(i - v[id].second);
    if(x > ans){
      id++;
    }
    ans = min(ans, x);
    printf("%d ", ans);
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
