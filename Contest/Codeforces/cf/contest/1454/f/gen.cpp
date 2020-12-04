#include<bits/stdc++.h>

using namespace std;

int main(){
  int n = 2e5, t = 1;
  cout << t << '\n';
  cout << n << '\n';
  for(int i = 0; i < n; i++) {
    if(i) cout << ' ';
    cout << i + 1;
  }
  cout << '\n'; 
}
