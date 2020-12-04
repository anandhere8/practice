#include<bits/stdc++.h>

#define EB emplace_back
#define int long long
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;
using pii = pair < int, int >;

void test_case(){
  int n;
  cin >> n;
  vector < vector < int >> A(n), tmp;
  for(int i = 0; i < n; i++){
    A[i].resize(2);
    cin >> A[i][0];
  }
  for(int i = 0; i < n; i++){
    cin >> A[i][1];
  }
  tmp = A;
  int ans = LLONG_MAX;

  for(int i = 0; i < n; i++){
    bool ok = true;
    priority_queue < pii, vector<pii>, greater<pii> > pq; 
    int sum = 0;
    A = tmp;
    for(int j = i; j < n; j++){
      pq.push({A[j][1], j});
      while((int)pq.size() && A[pq.top().S][0] == 0){
        pq.pop();
      }
      if((int)pq.size() == 0){
        //cerr << i << " " << j << endl;
        ok = false;
        break;
      }
      A[pq.top().S][0]--;
      //cerr << pq.top().F << " ";
      sum += pq.top().F;
    }
    for(int j = 0; j < i; j++){
      pq.push({A[j][1], j});
      while((int)pq.size() && A[pq.top().S][0] == 0){
        pq.pop();
      }
      if((int)pq.size() == 0){
        //cerr << i << " " << j << endl;
        ok = false;
        break;
      }
      A[pq.top().S][0]--;
      //cerr << pq.top().F << " ";
      sum += pq.top().F;
    }
    //cerr << i << " " << sum << " " << ok << endl;
    if(ok) ans = min(ans, sum);
  }
  cout << ans;
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
