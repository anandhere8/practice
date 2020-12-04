#include <bits/stdc++.h>
 
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define setIO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int) (x).size()
#define lc(i) 2*i
#define rc(i) 2*i+1
//#define int long long
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vii = vector<ii>;
using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;
using vvb = vector<vb>;
 
const int N = 1e5 + 5, MOD = 1e9 + 7, INF = 1e9 + 5;
 
signed main() {
    FAST_IO;
#ifdef arujbansal_local
    setIO("input.txt", "output.txt");
#endif
 
    int n, m, d, k;
    cin >> n >> m >> d >> k;
 
    vvi dp(n + 2, vi(m + 2, 0));
 
    char grid[n + 2][m + 2];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] != 'S') continue;
 
            dp[max(1, i - d)][max(1, j - d)]++;
            dp[min(n, i + d) + 1][max(1, j - d)]--;
 
            dp[max(1, i - d)][min(m, j + d) + 1]--;
            dp[min(n, i + d) + 1][min(m, j + d) + 1]++;
            for(auto x : dp){
              for(auto y : x){
                int cnt = 3;
                if(y == -1) cout << '\b';
                cout << y ;
                while(cnt--) cout << " ";
              }
              cout << endl;
            }
            cout << endl;
        }
    }
 
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dp[i][j] += dp[i - 1][j];
 
    int ans = 0;
    
    for(auto x : dp){
              for(auto y : x){
                int cnt = 3;
                if(y == -1) cout << '\b';
                cout << y ;
                while(cnt--) cout << " ";
              }
              cout << endl;
            }
            cout << endl;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] += dp[i][j - 1];
            ans += (grid[i][j] == 'M' && dp[i][j] >= k);
        }
    }
 
    cout << ans;
}
