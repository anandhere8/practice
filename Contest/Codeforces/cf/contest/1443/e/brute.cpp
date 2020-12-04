#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  int A[n];
  iota(A, A + n, 1);
  int cnt = 0;
  do{
    cnt %= (n * (n - 1)) / 2;
    cout << cnt++ << " : ";
    for(int i : A){
      cout << i << " ";
    }
    cout << endl;
  }while(next_permutation(A, A + n));
  
  return 0;
}
