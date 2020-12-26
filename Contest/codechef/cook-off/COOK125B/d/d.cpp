#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt = 1; 
  cin >> tt;
  
  auto test_case = [&](){
    int n, m;
    cin >> n >> m;
    vector<int> A(m);
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < m; i++){
      cin >> A[i];
      // if(A[i] ==)
      //pq.push(A[i]);
    }
    int tmp = n;
    int cnt = 0;
    while(n > 0){
      int min = 1e12;
      for(auto x : A){
        int tp = x;
        if(tp >= n){
          tp %= n;
        }
        if(tp){
          if(min > tp) min = tp;
        }
      }
      if(min == 1e12) break;
      // cerr << min << endl;
      cnt += n - min;
      n = min;
    }
    assert(cnt < tmp);
    cout << cnt;
  }; 
  while(tt--){
    test_case();
    cout << endl;
  }
  return 0;
}
