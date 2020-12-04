#include<bits/stdc++.h>

#define EB emplace_back
#define int long long
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

int A[102][102];

vector < pair < int, int >> v;
int n, m;
void o3(int i, int j){
  //cerr << i << " " << j << endl;
  for(int x = 0; x <= 1; x++){
    for(int y = 0; y <= 1; y++){
      //cerr << x + i << " " << y + j << endl;
      if(A[i + x][j + y]){
        v.push_back({x + i, y + j});
        A[x + i][y + j] = !A[x + i][y + j];
      }
    }
  }
}

void o2(int i, int j){
  int cnt = 0;
  bool ok = true;
  for(int x = 0; x <= 1; x++){
    for(int y = 0; y <= 1; y++){
      if(A[i + x][j + y]){
        if(ok){
          v.push_back({x + i, y + j});
          A[x + i][y + j] = !A[x + i][y + j];
          ok = false;
        }
      }
      else if(cnt < 2){
        v.push_back({x + i, y + j});
        A[x + i][y + j] = !A[x + i][y + j];
        cnt++;
      }
    }
  }
  o3(i, j);
}

void o1(int i, int j){
  int cnt = 0;
  for(int x = 0; x <= 1; x++){
    for(int y = 0; y <= 1; y++){
      if(A[i + x][j + y]){
        v.push_back({x + i, y + j});
        A[x + i][y + j] = !A[x + i][y + j];
      }
      else if(cnt < 2){
        v.push_back({x + i, y + j});
        A[x + i][y + j] = !A[x + i][y + j];
        cnt++;
      }
    }
  }
  o2(i, j);
}

void o4(int i, int j){
  int cnt = 0;
  for(int x = 0; x <= 1; x++){
    for(int y = 0; y <= 1; y++){
      if(cnt < 3){
        v.push_back({x + i, y + j});
        A[x + i][y + j] = !A[x + i][y + j];
        cnt++;
      }
    }
  }
  o1(i, j);
}

void solve(int i, int j){
  cerr << i << " " << j << endl;
  return;
  int cnt = 0;
  for(int x = 0; x <= 1; x++){
    for(int y = 0; y <= 1; y++){
      if(A[i + x][j + y]){
        cnt++;
      }
    }
  }
  if(cnt == 0){
    return;
  }
  if(cnt == 1){
    o1(i, j);
  }
  else if(cnt == 2){
    o2(i, j);
  }
  else if(cnt == 3){
    o3(i, j);
  }
  else {
    o4(i, j);
  }
}
    

void test_case(){
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    string s; cin >> s;
    for(int j = 0; j < m; j++){
      A[i][j] = s[j] - '0';
    }
  }
  
  
  for(int i = 0; i < n; i += 2){
    for(int j = 0; j < m; j += 2){
      //cerr << i << " " << j << endl;
      solve(i, j);
    }
  }
  for(int i = 0; i < m - 1; i += 2){
    solve(n - 2, i);
  }
  for(int i = 0; i < n - 1; i += 2){
    solve(i, m - 2);
  }
  cout << (int)v.size() / 3 << endl;
  int cnt = 0;
  for(auto &[x, y] : v){
    cout << x + 1 << " " << y + 1 << " ";
    cnt++;
    if(cnt % 3 == 0) cout << endl;
  }
  v.clear();
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
