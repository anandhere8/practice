#include<bits/stdc++.h>
#define int long long
using namespace std;

void test_case(){
	int n;
	cin >> n;
  vector<int> A(n + 1);
  auto ok = [&](int x){
    int tmp = x;
    while(x){
      if(x % 10 == 7){
        return true;
      }
      x /= 10;
    }
    while(tmp){
      if(tmp % 8 == 7){
        return true;
      }
      tmp /= 8;
    }
    return false;
  };
  int sum = 0;
  for(int i = 1; i <= n; i++){
    if(!ok(i)){
      ++ sum;
    }
  }
  cout << sum;
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt = 1; 
  // cin >> tt;
  while(tt--){
    test_case();
    cout << endl;
  }
  return 0;
}
