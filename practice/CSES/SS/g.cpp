#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  vector < int > A(n);
  map<int, int > mp;
  for(int i = 0; i < n; i++){
    cin >> A[i];
    if(mp.count(m - A[i])){
      cout << mp[m - A[i]] << " " << i + 1 << endl;
      return 0;
    }
    mp[A[i]] = i + 1;
  }
  cout << "IMPOSSIBLE" << endl;
  return 0;
}