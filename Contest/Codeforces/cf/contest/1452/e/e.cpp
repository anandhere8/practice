#include<bits/stdc++.h>

#define EB emplace_back
#define int long long
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;


int32_t main(){
  int n; cin >> n;
  int A[n][n];
  int mark[n] = {};
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> A[i][j];
    }
  }
  vector < int > qq(n); 
  for(auto &x : qq){
    cin >> x;
    x--;
  }
  
  reverse(all(qq));
  vector < int > res;
  for(int k = 0; k < n; k++){
    int x = qq[k];
    mark[x] = 1;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        A[i][j] = min(A[i][j], A[i][x] + A[x][j]);
      }
    }
    
    if(k == 2){
      for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
          cerr << A[i][j] << " ";
        }
        cerr << endl;
      }
    }
    
    int sum = 0;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(mark[i] && mark[j]) sum += A[i][j];
      }
    }
    res.EB(sum);
  }
  reverse(all(res));
  for(int x : res) cout << x << " ";
  return 0;
}


