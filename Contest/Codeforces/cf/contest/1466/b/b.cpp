#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int tt = 1; 
  cin >> tt;
  // Focus
  auto test_case = [&](){
    map<int, int> mp;
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++){
      cin >> A[i];
      if(mp.count(A[i])){
        A[i] += 1;
      }
      mp[A[i]]++;
    }
    cout << mp.size();
  };  
  while(tt--){
    test_case();
    cout << endl;
  }
  return 0;
}
