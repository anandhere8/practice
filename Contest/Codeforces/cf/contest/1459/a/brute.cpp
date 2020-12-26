#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, m;
  cin >> n;
  m = n;
  vector < int > A(n), B(m);
  vector<int> aa, bb;
  for(int i = 0; i < n; i++){
    cin >> A[i];
    aa.emplace_back(i);
  }
  for(int i = 0; i < m; i++){
    cin >> B[i];
    bb.emplace_back(i);
  }
  sort(aa.begin(), aa.end()), sort(bb.begin(), bb.end());
  sort(A.begin(), A.end()), sort(B.begin(), B.end());
  map<int, int> mp;
  int R = 0, Bl = 0;
  do{
    int cnt = 0;
    do{
      int a = 0, b = 0;
      for(auto &xax : aa){
        a *= 10;
        a += A[xax];
      }
      for(auto &xax : bb){
        b *= 10;
        b += B[xax];
      }
      if(a > b) {
        R++;
        mp[A[aa[0]]]++;
      }
      else if(b > a) Bl++;

    }while(next_permutation(aa.begin(), aa.end()));
  }while(next_permutation(bb.begin(), bb.end()));
  for(auto x : mp) cerr << x.first << " " <<  x.second << endl;
  cout << "RED :" << R << endl;
  cout << "BLUE :" << Bl << endl;
  return 0;
}