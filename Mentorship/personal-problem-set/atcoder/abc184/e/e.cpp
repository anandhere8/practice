#include <bits/stdc++.h>

using namespace std;

using pii = pair < int, int >;

const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0}, N = 2005;
char A[N][N];
bool ok[N][N];
int dist[N][N];
int n, m, si, sj, gi, gj;

bool fine(int x, int y){
  if(x < 1 || x > n || y < 1 || y > m){
    return false;
  }
  if(A[x][y] == '#') return false;
  if(ok[x][y]) return false;
  return true;
}

int main(){
  cin >> n >> m;
  vector < vector < pii >> F(26);
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      cin >> A[i][j];
      if(A[i][j] == '.' || A[i][j] == '#') continue;
      if(A[i][j] == 'S'){
        si = i, sj = j;
        continue;
      }
      if(A[i][j] == 'G'){
        gi = i, gj = j;
        continue;
      }
      F[A[i][j] - 'a'].emplace_back(i, j);
    }
  }
  queue < pii > que;
  bool done[26] = {};
  que.push({si, sj});
  ok[si][sj] = true;
  while(!que.empty()){
    auto &[px, py] = que.front(); que.pop();
    //cerr << "par : " <<  px << " " << py << endl;
    for(int i = 0; i < 4; i++){
      int x = dx[i] + px, y = dy[i] + py;
      if(x == gi && y == gj){
        cout << dist[px][py] + 1 << endl;
        return 0;
      }
      if(fine(x, y)){
        dist[x][y] = 1 + dist[px][py];
        que.push({x, y});
        ok[x][y] = true;
        //cerr << x << " " << y << endl;
      }
    }
    if(A[px][py] >= 'a' && A[px][py] <= 'z'){
      if(!done[A[px][py] - 'a']){
        done[A[px][py] - 'a'] = true;
        for(auto &[x, y] : F[A[px][py] - 'a']){
          if(!ok[x][y]) {
            dist[x][y] = 1 + dist[px][py];
            que.push({x, y});
            //cerr << x << " " << y << endl;
          }          
          if(x == gi && y == gj){
            cout << dist[px][py] + 1 << endl;
            return 0;
          }
          ok[x][y] = true;
        }
      }
    }    
  }
  cout << -1 << endl;
  return 0;
}
