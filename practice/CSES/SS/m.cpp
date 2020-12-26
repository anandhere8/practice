#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
#define f first
#define s second
 
#define int long long
 
const int INF=1e9+7;
const int sz=1e5+1;
int n, m, k, p ,x, y, a, b, c, d;
bool cmp(pair<int,int> &a, pair<int,int> &b){
    if(a.f == b.f)return a.s < b.s;
    return a.f < b.f;
}

void solve(){
    cin>>n;
    vector<pair<int,int>> ev;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        //if(a==b)continue;
        ev.push_back({a, +i+1});
        ev.push_back({b, -i-1});
    }
    sort(ev.begin(), ev.end(), cmp);
    int rooms=0, streak=0;
    vector<int> in(n);
    set<int> free;
    for(int i=0;i<ev.size();i++){
        //cout<<ev[i].f<<" "<<ev[i].s<<"\n";
        if(ev[i].s > 0){
            if(free.size() == 0)x = ++rooms;
            else x = *free.begin(), free.erase(free.begin());
            in[ev[i].s-1]=x;
        } else {
            free.insert(in[-ev[i].s-1]);
        }
    }
    cout<<rooms<<"\n";
    for(int i=0;i<n;i++)cout<<in[i]<<" ";
}
int32_t main(){
  ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t = 1; 
    //cin >> t; 
    while (t--) { 
        solve();  
    }
    #ifdef HACKX
      cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    #endif
    return 0; 
}