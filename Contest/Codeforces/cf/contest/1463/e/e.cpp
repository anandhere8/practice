#include<bits/stdc++.h>
#define int long long
using namespace std;

void test_case(){
	int n, m;
  cin >> n >> m;
  int k; cin >> k;
  vector < int > A(n);
  int res = 0;
  int sum = 0;
  bool ok = true;
  for(int i = 0; i < n; i++){
    cin >> A[i];
    if(sum + A[i] <= m && ok){
      sum += A[i];
      int tmp = sum / k;
      res += tmp;
      sum -= tmp * k;
    }
    else{
      ok = false;
    }
  }
  if(ok){
    if(sum) res++;
  }
  cout << res;
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
