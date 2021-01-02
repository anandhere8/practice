#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int tt = 1; 
  cin >> tt;
  // Focus
  auto test_case = [&](){
    int n;
    cin >> n;
    vector<int> A(n);
    int res = 0;
    set<int> st;
    for(int i = 0; i < n; i++){
      cin >> A[i];
    }
    for(auto i = 0; i < n; ++ i){
      for(auto j = i + 1; j < n; ++ j){
        st.insert(abs(A[i] - A[j]));
      }
    }
    cout << (int)st.size();
  };  
  while(tt--){
    test_case();
    cout << endl;
  }
  return 0;
}
