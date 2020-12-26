#include<bits/stdc++.h>
#define int long long
using namespace std;

void test_case(){
  int n;
 cin >> n;
 vector < int > A(n);
 for(int i = 0; i < n; i++){
   cin >> A[i];
 }
 int l = 0, r = n - 1;
 while(l < r){
  cout << A[l] << " ";
  cout << A[r] << " ";
  l++, r--;
 } 
 if(l == r) cout << A[l];
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt = 1; 
  cin >> tt;
  while(tt--){
    test_case();
    cout << endl;
  }
  return 0;
}
