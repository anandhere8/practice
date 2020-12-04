#include<bits/stdc++.h>

#define EB emplace_back
#define int long long
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

bool prime(int x){
  for(int i = 2; i * i <= x; i++){
    if(x % i == 0){
      return false;
    }
  }
  return true;
}

void test_case(){
  int cnt = 0;
  int sum = 1;
  for(int i = 2; sum <= 1e6; i++){
    if(prime(i)){
      sum *= i;
      cnt++;
    }
  }
  cout << cnt;
}

int32_t main(){
  IOS;
  int tt = 1; 
  //cin >> tt;
  while(tt--){
    test_case();
    cout << endl;
  }
  return 0;
}
