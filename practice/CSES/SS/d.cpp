#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> A(n);
  vector<int> B(m);
  multiset < int > mul;
  const int INF = 2e9 + 20;
  mul.insert(-1);
  mul.insert(INF);
  for(int i = 0; i < n; i++){
    cin >> A[i];
    mul.insert(A[i]);
  }
  
  for(int i = 0; i < m; i++){
    int x;
    cin >> x;
    auto it = mul.lower_bound(x + 1);
    it--;
    cout << *it << endl;
    if(*it != -1){
      mul.erase(it);
    }
  }
    
  return 0;
}