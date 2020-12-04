#include<bits/stdc++.h>

#define EB emplace_back
#define int long long
#define F first
#define S second
#define all(x) x.begin(),x.end()
//#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

string a(){
  return "AND ";
}
string o(){
  return "OR ";
}
string x(){
  return "XOR ";
}

void test_case(){
  int n; cin >> n;
  cout << a() << 1 << " " << 2 << endl;
  int anb; cin >> anb;
  cout << x() << 1 << " " << 2 << endl;
  int axb; cin >> axb;
  cout << a() << 3 << " " << 2 << endl;
  int bnc; cin >> bnc;
  cout << x() << 3 << " " << 2 << endl;
  int bxc; cin >> bxc;
  cout << a() << 1 << " " << 3 << endl;
  int anc; cin >> anc;
  int axc = axb ^ bxc;
  int sum_ab = axb + 2 * anb;
  int sum_bc = bxc + 2 * bnc;
  int sum_ac = axc + 2 * anc;
  vector < int > res(n);
  res[0] = (sum_ab - sum_bc + sum_ac) / 2;
  res[1] = sum_ab - res[0];
  res[2] = sum_bc - res[1];
  for(int i = 3; i < n; i++){
    cout << x() << 1 << " " << i + 1 << endl;
    int tmp; cin >> tmp;
    res[i] = res[0] ^ tmp;
  }
  cout << "! ";
  for(int c : res) cout << c << " ";
}

int32_t main(){
  IOS;
  int tt = 1; 
  //cin >> tt;
  while(tt--){
    test_case();
    cout << endl;
  }
  return 0;
}
