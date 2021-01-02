#include<bits/stdc++.h>
// #define int long long
using namespace std;

const int MAX = 60;
int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int tt = 1;   
  auto test_case = [&](){
    auto Isprime = [&](int x){
      for(int j = 2; j * j <= x; ++ j){
        if(x % j){
          return false;
        }
      }
      return true;
    };

    int n;
    cin >> n;
    vector<int> A(n + 1);
    for(int i = 1; i <= n; i++){
      cin >> A[i];
    }
    vector<int> primes;
    for(int i = 2; i < MAX; ++ i){
      if(Isprime(i)){
        primes.emplace_back(i);
      }
    }
    int N = (int)primes.size();
    for(int i = 1; i < MAX; ++ i){
      for(int j = 0; j < N; ++ j){
        if(i % primes[j]){
          
        }
      }
    }
  };
  while(tt--){
    test_case();
    cout << endl;
  }
  return 0;
}
