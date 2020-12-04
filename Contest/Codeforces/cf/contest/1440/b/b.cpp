#include<bits/stdc++.h>

#define EB emplace_back
#define int long long
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

void test_case(){
  int n, k; cin >> n >> k;
  int A[n * k + 1];
  for(int i = 1; i <= n * k; i++){
    cin >> A[i];
  }
  int sm1 = 0;
  int dec = n / 2 + 1;
  for(int i = n * k - dec + 1; i > 0 && k--; i -= dec){
    sm1 += A[i];
    cerr << A[i] << " ";
  }
  cout << sm1 << endl;
}

int32_t main(){
	IOS;
	int tt = 1; 
  cin >> tt;
	while(tt--){
    test_case();
	}
	return 0;
}
