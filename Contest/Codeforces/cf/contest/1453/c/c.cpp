#include<bits/stdc++.h>

#define EB emplace_back
#define int long long
#define double long long
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

double area(int a, int d, int b, int e, int c, int f)
{
    int x[] = {a, b, c};
    int y[] = {d, e, f};
    int sum = 0;
    for(int i = 0; i < 3; i++){
      sum += x[i] * (y[(i + 1) % 3] - y[(i + 2) % 3]);
    }
    return abs(sum);
}

void test_case(){
  int n;
  cin >> n;
  vector < vector < pair < int, int >>> v(10);
  string A[n];
  for(int i = 0; i < n; i++){
    cin >> A[i];
    for(int j = 0; j < n; j++){
      v[A[i][j] - '0'].EB(i, j);
    }
  }
  //exit(0);
  for(int i = 0; i < 10; i++){
    sort(all(v[i]));
  }
  int ans[10] = {};
  for(int k = 0; k < 10; k++){
    int res = 0;
    for(int i = 0; i < n; i++){
      pair < int, int > f = {-1, -1}, s = f, tmp = f;
      for(int j = 0; j < n; j++){
        if((A[i][j] - '0') == k){
          if(f == tmp){
            f = {i, j};
          }
          s = {i, j};
        }
      }
      int ff = abs(f.S - s.S + 1) * max(i, n - i);
      res = max(res, ff);
    }
    ans[k] = max(ans[k], res);
  }
  
  for(int j = 0; j < n; j++){
    for(int i = 0; i < n / 2; i++){
          swap(A[i][j], A[n - i - 1][j]);
      }
  }
  for(int i = 0; i < n; i++){
      for(int j = 0; j < i; j++){
          swap(A[i][j], A[j][i]);
      }
  }
  
  for(int k = 0; k < 10; k++){
    int res = 0;
    for(int i = 0; i < n; i++){
      pair < int, int > f = {-1, -1}, s = f, tmp = f;
      for(int j = 0; j < n; j++){
        if((A[i][j] - '0') == k){
          if(f == tmp){
            f = {i, j};
          }
          s = {i, j};
        }
      }
      res = max(res, abs(f.S - s.S + 1) * max(i, n - i));
    }
    if(k == 1) {
      cerr << res;
      exit(0);
    }
    ans[k] = max(ans[k], res);
  }
  for(int k = 0; k < 10; k++){
    if((int)v[k].size() == 0) continue;
    auto [x, y] = v[k][0];
    auto [a, b] = v[k].back();
    int res = 0;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(x == a || y == b){
          res = max(res, area(x, y, a, b, i , j));
        }
        else{
          if(i == x || j == y || i == a || j == b){
            res = max(res, area(x, y, a, b, i , j));
          }
        }
      }
    }
    ans[k] = max(ans[k], res);
  }
  for(int i = 0; i < 10; i++) cout << ans[i] << " ";
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
