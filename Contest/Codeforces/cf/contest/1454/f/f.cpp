#include <bits/stdc++.h>

using namespace std;

template<class T, class U> T &cmax(T &x, U &y) {return x = max<T>(x, y);}

int main(){
  auto test = [&](){
    int n;
    cin >> n;
    vector < int > A(n + 2), left(n + 2), right(n + 2), premax(n + 2), postmax(n + 2);
    A[0] = -1, A[n + 1] = -1;
    map<int, vector<int>> mp;
    stack<int> stkl, stkr;
    stkl.push(0), stkr.push(n + 1);
    for(auto i = 1; i < n + 1; ++ i){
      cin >> A[i];
      mp[A[i]].emplace_back(i);
      premax[i] = A[i];
      postmax[i] = A[i];
      while(A[stkl.top()] >= A[i]) stkl.pop();
      left[i] = stkl.top();
      stkl.push(i);
      cmax(premax[i], premax[i - 1]);
    }
    
    for(auto i = n; i > 0; -- i){
      cmax(postmax[i], postmax[i + 1]);
      while(A[stkr.top()] >= A[i]) stkr.pop();
      right[i] = stkr.top();
      stkr.push(i);
    }
    static int dx[] = {1, 0};
    static int dy[] = {0, -1};
    for(auto i = 2; i < n; ++ i){
      for(auto j = 0; j < 2; j++){
        for(auto k = 0; k < 2; k++){
          int l = left[i], r = right[i];
          l += dx[j], r += dy[k];
          if(l >= i || r <= i) continue;
          if(premax[l] == postmax[r] && premax[l] == A[i]){
            cout << "YES " << endl;
            cout << l << " " << r - l - 1 << " " << n - r + 1;
            return ;
          }
        }
      }
    }
    cout << "NO" << endl;
  };
  int tt;
  cin >> tt;
  while(tt--){
    test();
    cout << endl;
  }
  return 0;
}