#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  vector < int > A(n);
  for(int i = 0; i < n; i++){
    cin >> A[i];
  }
  int res = A[0];
  for(auto i = 0; i < n; ++ i){
    for(auto j = i; j < n; ++ j){
      priority_queue<int, vector<int>, greater<>> a;
      priority_queue<int > b;
      for(int ii = i; ii <= j; ii++){
        a.push(A[ii]);
      }
      for(int ii = 0; ii < i; ii++){
        b.push(A[ii]);
      }
      for(int ii = j + 1; ii < n; ii++){
        b.push(A[ii]);
      }
      int tmp = m;
      while((int)a.size() && (int)b.size() && tmp--){
        if(a.top() > b.top()) break;
        a.pop();
        a.push(b.top());
        b.pop();
      }
      int sum = 0;
      while((int)a.size()){
        sum += a.top();
        a.pop();  
      }
      res = max(res, sum);
    }
  }
  cout << res;
  return 0;
}