#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> A(n);
  for(int i = 0; i < n; i++){
    cin >> A[i];
  }
  for(auto i = 0; i < n; ++ i){
    long long sum = 0;
    for(auto j = 0; j < n; ++ j){
      sum += (A[i] | A[j]);
    }
    cout << sum << endl;
  }
  return 0;
}