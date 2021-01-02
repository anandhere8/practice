#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define PI acos(-1)
#define int long long int
#define pb push_back
#define pi pair<int, int>
#define pii pair<int, pi>
#define fir first
#define sec second
#define DEBUG 0
#define MAXN 200001

int n;
int grau[MAXN];
int color[MAXN];
bool visited[MAXN];
vector<int> adj[MAXN];

struct cmp
{
  bool operator()(const int &lhs, const int &rhs)
  {
    return lhs < rhs;
  }
  bool operator()(const pi &lhs, const pi &rhs)
  {
    if (lhs.fir != rhs.fir)
      return lhs.fir > rhs.fir;
    return lhs.sec < rhs.sec;
  }
};
signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int q;
  cin >> q;
  while (q--)
  {
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      cin >> color[i];
      adj[i].clear();
      grau[i] = 0;
      visited[i] = false;
    }
    vector<int> ans;
    int curr = 0;
    for (int i = 0; i < n - 1; i++)
    {
      int a, b;
      cin >> a >> b;
      a--, b--;
      adj[a].pb(b);
      adj[b].pb(a);
      curr += (color[a] + color[b]);
      grau[a]++;
      grau[b]++;
    }
    multiset<pi, cmp> dif;
    for (int i = 0; i < n; i++)
      dif.insert({grau[i], color[i]});
    ans.pb(curr);
    while (ans.size() < n - 1)
    {
      pi at = *dif.begin();
      dif.erase(*dif.begin());
      curr -= at.sec;
      ans.pb(curr);
      at.fir--;
      dif.insert(at);
    }
    reverse(ans.begin(), ans.end());
    for (auto const &i : ans)
      cout << i << " ";
    cout << endl;
  }
  return 0;
}
// cada aresta com exatamente 1 cor
// voce nao precisa usar cada cor
// valor componente = soma dos vertices