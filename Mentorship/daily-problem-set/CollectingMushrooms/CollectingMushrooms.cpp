#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, m, k, d;
  scanf("%d%d%d%d", &n, &m, &k, &d);
  //int dp[n + 2][m + 2];
  vector < vector < int >> dp(n + 2, vector < int > (m + 2, 0));
  //char grid[n + 2][m + 2];
  //memset(dp, 0, sizeof dp);
    char grid[n + 2][m + 2];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] != 'S') continue;
 
            dp[max(1, i - d)][max(1, j - d)]++;
            dp[min(n, i + d) + 1][max(1, j - d)]--;
 
            dp[max(1, i - d)][min(m, j + d) + 1]--;
            dp[min(n, i + d) + 1][min(m, j + d) + 1]++;
        }
    }
 
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dp[i][j] += dp[i - 1][j];
 
    int ans = 0;
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] += dp[i][j - 1];
            ans += (grid[i][j] == 'M' && dp[i][j] >= k);
        }
    } 
    cout << ans;
}
