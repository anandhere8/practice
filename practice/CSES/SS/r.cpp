#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> A(n + 1);
  for(auto i = 1; i < n + 1; ++ i){
    cin >> A[i];
  }
  stack<int> stk;
  stk.push(0);
  for(auto i = 1; i < n + 1; ++ i){
    while(A[stk.top()] >= A[i]){
      stk.pop();
    }
    cout << stk.top() << " ";
    stk.push(i);
  }
  return 0;
}