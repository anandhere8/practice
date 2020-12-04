#include<bits/stdc++.h>

#define EB emplace_back
#define int long long
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

vector < int > a, b;
int A[50], B[50], n, m, T;
void solve1(int i, int sum){
  if(i == n){
    //cerr << sum << ' ';
    a.EB(sum);
    return;
  }
  solve1(i + 1, sum); 
  solve1(i + 1, (sum + A[i]) % T); 
}

void solve2(int i, int sum){
  if(i == m){
    b.EB(sum);
    return;
  }
  solve2(i + 1, sum);
  solve2(i + 1, (sum + B[i]) % T);
}


int32_t main(){
  int p; cin >> p >> T;
  n = p / 2, m = p - n;
  for(int i = 0; i < n; i++){
    cin >> A[i];
  }
  for(int i = 0; i < m; i++){
    cin >> B[i];
  }
  solve1(0, 0);
  solve2(0, 0);
  b.EB(0);
  a.EB(0);
  b.EB(1e12);
  a.EB(1e12);
  sort(all(a));
  sort(all(b));
  T--;
  //for(auto x : a) cerr << x << " ";
  //cerr << endl;
  //for(auto x : b) cerr << x << " ";
  //cerr << endl;
  //return 0;
  int ans = 0;
  for(auto x : a){
    if(x > T) continue;
    int search = T - x;
    auto it = lower_bound(all(b), search);
    if(*it != search) --it;
    if(x + *it <= T)
      ans = max(ans, x + *it);
  }
   for(auto x : b){
    if(x > T) continue;
    int search = T - x;
    auto it = lower_bound(all(a), search);
    if(*it != search) --it;
    if(x + *it <= T)
      ans = max(ans, x + *it);
  }
  cout << ans << endl;
  return 0;
}
