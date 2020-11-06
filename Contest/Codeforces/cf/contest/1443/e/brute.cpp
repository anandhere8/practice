#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  int A[n];
  iota(A, A + n, 1);
  do{
    for(int i : A){
      cout << i << " ";
    }
    cout << endl;
  }while(next_permutation(A, A + n));
  
  return 0;
}
