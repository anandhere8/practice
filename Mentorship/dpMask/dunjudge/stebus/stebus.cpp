#include <bits/stdc++.h>

using namespace std;
vector<int> v;
int arr[4];

void solve(int i, int sum){
  if(i == 4){
    v.emplace_back(sum);
    return;
  }
  solve(i + 1, sum);
  solve(i + 1, sum + arr[i]);
}

int main(){
  int n;
  cin >> n;
  // assert(n <= 2);
  vector<int> A(1 << n);
  for(auto &xax : A){
    cin >> xax;
  } 

  int a1 = A[1];



  auto ok = [&](int a, int b, int c, int d){
    v.clear();
    arr[0] = a, arr[1] = b, arr[2] = c, arr[3] = d;
    solve(0, 0);
    sort(v.begin(), v.end());
    return v == A;
  };
  if(n >= 1){
    cout << A[1] << endl;
  }
  if(n >= 2){
    cout << A[2] << endl;
  }
  if(n == 3){
    cout << A.back() - A[1] - A[2] << endl;
  }
  if(n == 4){
    int a = A[1], b = A[2];
    for(int i = 0; i <= 1e5; ++ i){
      int c = i, d = A.back() - a - b - c;
      if(d < 0) continue;
      if(ok(a, b, c, d)){
        cout << c << endl;
        cout << d << endl;
        return 0;
      }
    }
  }

  return 0;
}