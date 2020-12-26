#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  swap(n, m);
  vector < int > A(n);
  set<int> st;
  st.insert(0), st.insert(m);
  for(int i = 0; i < n; i++){
    cin >> A[i];
    st.insert(A[i]);
  }
  vector<int> O = A;
  O.emplace_back(0), O.emplace_back(m);
  sort(O.begin(), O.end());
  reverse(A.begin(), A.end());
  int ans = 0;
  for(auto i = 1; i <= n + 1; ++ i){
    ans = max(ans, O[i] - O[i - 1]);
  }
  vector<int> res;
  res.emplace_back(ans);
  for(auto i = 0; i < n - 1; ++ i){
    auto it = st.lower_bound(A[i]);
    auto tmp1 = it, tmp2 = it;
    tmp1--, tmp2++;
    ans = max(ans, *tmp2 - *tmp1);
    res.emplace_back(ans);
    st.erase(it);
  }
  reverse(res.begin(), res.end());
  for(auto &xax : res){
    cout << xax << " ";
  }
  return 0;
}