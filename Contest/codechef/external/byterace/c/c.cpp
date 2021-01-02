#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int tt = 1; 
  cin >> tt;
  
  auto test_case = [&](){
    int n, k;
    cin >> n >> k;
    vector<int> A(n + 2);
    vector<int> F(n + 2);
    for(auto i = 1; i <= n; ++ i){
      F[i] = i;
      
    }
    vector<int> st(n + 2), end(n + 2);
    for(auto i = 0; i < k; ++ i){
      int x, y;
      cin >> x >> y;
      st[x]++;
      st[y + 1]--;
      end[y + 1] += x - 1;
    }
    int lst = 0;
    int x = 0;
    for(auto i = 1; i <= n; ++ i){
      if(st[i]){
        lst += st[i] * (i - 1);
      }
      if(end[i]){
        lst -= end[i];
      }
      st[i] += st[i - 1];
      A[i] = A[i - 1] + i * st[i] - lst;
    }
    for(auto i = 1; i < n + 1; ++ i){
      cout << A[i] << " ";
    }
  };  
  while(tt--){
    test_case();
    cout << endl;
  }
  return 0;
}
