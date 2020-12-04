#include <bits/stdc++.h>
#define int long long

using namespace std;

vector < int > num;
int dp[20][20][2];
int solve(int i,int st,int f) {
  if(i > (int)num.size()) return 1;
  if(dp[i][st][f]!=-1) return dp[i][st][f];
  //cerr << "ok " << endl;
  int sol=0;
  if(f==1) {
    if(st==0) sol += solve(i+1, st, !num[i - 1]);
    else if((i-st+1)%2==0) sol+=solve(i+1, st, !num[i - 1]);
    for(int curr=1; curr <= num[i - 1]; curr++) {
      if(st==0) {
        if(curr % 2 ==0) continue;
        sol+=solve(i+1, i, curr == num[i - 1]);
      }
      else {
        if(curr % 2 == (i-st+1) % 2) {
          sol+=solve(i+1, st, curr==num[i - 1]);
        }
      }
    }
  }
  else {
    if(st==0) sol+=solve(i+1,st,0);
    else if((i-st+1)% 2== 0) sol+=solve(i+1,st,0);
    for(int curr = 1; curr <= 9; curr++) {
      if(st == 0) {
        if(curr % 2 == 0) continue;
        sol+= solve(i+1, i, 0);
      }
      else {
        if(curr % 2 == (i-st+1) % 2) {
          sol+= solve(i+1, st, 0);
        }
      }
    }
  }
  return dp[i][st][f]=sol;
}
void init() {
  for(int i=0;i<20;i++) {
    for(int j=0;j<20;j++) dp[i][j][0] = -1, dp[i][j][1] = -1;
  }
}

int32_t main(){
  int tt; cin >> tt;
  for(int cases=1; cases <= tt; cases++) {
    int l, r; cin >> l >> r;
    l--;
    num.clear();
    while(l > 0) {
      num.push_back((l%10));
      l/=10;
    }
    reverse(num.begin(), num.end());
    init();
    l = solve(1,0,1);
    
    num.clear();
    while(r > 0) {
      num.push_back(r%10);
      r/=10;
    }
    reverse(num.begin(), num.end());
    init();
    r =solve(1,0,1);
    int ans = r - l;
    cout << "Case #" << cases << ": " << ans << endl;
  }
  return 0;
}
