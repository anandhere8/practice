#include<bits/stdc++.h>

#define EB emplace_back
#define int long long
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

void a(){
  cout << "Ashish";
}

void b(){
  cout << "Utkarsh";
}

void test_case(){
  int d, k; cin >> d >> k;
  int n = 0, x = 0, y = 0;;
  int cnt = 0;
  while(x + k <= d){
    x += k;
    cnt++;
    y = sqrt(d * d - x * x);
    int rest = y / k;
    n = max(n, rest + cnt);
    //cerr << x << " " << y << endl;
  }
  if(n % 2){
    a();
  }
  else{
    b();
  }
}

int32_t main(){
  IOS;
  int tt = 1; 
  cin >> tt;
  while(tt--){
    test_case();
    cout << endl;
  }
  return 0;
}
