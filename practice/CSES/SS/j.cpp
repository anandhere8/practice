#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector < int > A(n);
  map<int, int > mp;
  int lst = -1;
  int ans = 0;
  for(int i = 0; i < n; i++){
    cin >> A[i];
    if(mp.count(A[i])){
      lst = max(lst, mp[A[i]]);
    }
    int tmp = i - lst;
    // cerr << tmp << endl;
    ans = max(ans, tmp);
    // 2
    mp[A[i]] = i;
  }
  cout << ans;
  return 0;
}