#include<bits/stdc++.h>

#define EB emplace_back
#define int long long
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

void test_case(){
  bool ok = true;
  int n, k; cin >> n >> k;
  string a, b; cin >> a >> b;
  sort(all(a)), sort(all(b));
  if(a > b){
    cout << "No";
    return;
  }
  int cnta[26] = {}, cntb[26] = {};
  for(char c : a){
    cnta[c - 'a']++;
  }
  for(char c : b){
    cntb[c - 'a']++;
  }
  for(int i = 0; i < 26; i++){
    if(cntb[i] == 0){
      continue;
    }
    if(cntb[i] <= cnta[i]){
      cnta[i] -= cntb[i];
    }
    else{
      cntb[i] -= cnta[i];
      cnta[i] = 0;
      if(cntb[i] % k != 0){
        cerr << "TEST" << endl;
        ok = false;
        break;
      }
      for(int j = 0; j < i && cntb[i]; j++){
        if(cnta[j] >= cntb[i]){
          cnta[j] -= cntb[i];
          break;
        }
        else{
          if(cnta[j] % k == 0){
            cntb[i] -= cnta[j];
            cnta[j] = 0;
          }
        }
      }
    }
  }
  for(int i = 0; i < 26; i++){
    if(cnta[i]){
      ok = false;
      //break;
    }
    //cerr << cnta[i] << " ";
  }
  if(ok) cout << "Yes";
  else cout << "No";        
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
