#include <bits/stdc++.h>

using namespace std;

int main(){
  string s;
  cin >> s;
  std::vector<string> v;
  sort(s.begin(), s.end());
  do{
    v.emplace_back(s);
  }while(next_permutation(s.begin(), s.end()));
  cout << (int)v.size() << endl;
  for(auto &xax : v){
    cout << xax << " " << endl;
  }
  return 0;
}