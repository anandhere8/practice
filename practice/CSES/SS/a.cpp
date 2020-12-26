#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  set < int > A;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    A.insert(x);
  }
  cout << (int)A.size();
  return 0;
}