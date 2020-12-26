#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n;
  cin >> n;
  int x;
  vector<int> v;
  v.emplace_back(0);
  for(int i = 0; i < n; i++){
    cin >> x;
    if(v.back() <= x){
      v.emplace_back(x);
    }
    else{
      int j = lower_bound(v.begin(), v.end(), x + 1) - v.begin();
      v[j] = x;
      // cerr << x << " " << j << endl;
    }
  }
  cout << v.size() - 1;
}