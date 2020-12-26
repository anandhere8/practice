#include<bits/stdc++.h>
#define int long long
using namespace std;

void test_case(){
	int n;
	cin >> n;
	vector < int > A(n + 1), pre(n + 2);
	for(int i = 1; i <= n; i++){
		cin >> A[i];
    pre[i] = A[i];
    pre[i] += pre[i - 1];
	}
  pre[n + 1] = 1e15;
  int ans = n - 1;
  for(int i = 1; i <= n; i++){
    int res = 0;
    int sum = pre[i] - pre[0];
    res += i - 1;
    bool ok = true;
    for(int j = i + 1; j <= n; j++){
      auto it = lower_bound(pre.begin(), pre.end(), pre[j - 1] + sum);
      // cerr << i << " " << j << " " << pre[j - 1] + sum << endl;
      if((*it - pre[j - 1]) != sum){
        ok = false;
        break;
      }
      else{
        int k = it - pre.begin();
        res += k - j;
        //cerr << k << " ";
        j = k;
      }
    }
    if(ok){
      ans = min(ans, res);
    }
  }
  cout << ans;
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
