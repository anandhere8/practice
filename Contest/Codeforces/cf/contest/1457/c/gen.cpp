#include <bits/stdc++.h>

using namespace std;

// constraints
const int lenl = 1,lenr = 10; // range of size of array
const int valuel = 1, valuer = 10; // range of value of array


int random(int a, int b){
  return (rand() % (b - a + 1) + a);
}

int main(int argc, char *argv[]){
  srand(atoi(argv[1]));
  cout << 1 << endl;
  int n = random(lenl, lenr);
  int p = random(lenl, n);
  int k = random(lenl, n);
  cout << n << " " << p << " " << k << endl;
  for(int i = 0; i < n; i++){
    int x = random(valuel, valuer);
    cout << x % 2;
  }
  cout << endl;
  int a = random(lenl, 100);
  int b = random(lenl, 100);
  cout << a << " " << b;
  cout << endl;
  return 0;
}
	
