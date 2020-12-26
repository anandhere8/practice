#include <bits/stdc++.h>

using namespace std;

// constraints
const int lenl = 1,lenr = 50; // range of size of array
const int valuel = 1, valuer = 1e9; // range of value of array


int random(int a, int b){
  return (rand() % (b - a + 1) + a);
}

int main(int argc, char *argv[]){
  srand(atoi(argv[1]));
  int n = random(lenl, lenr);
  cout << n << endl;
  for(int i = 0; i < n; i++){
    int x = random(valuel, valuer);
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
	
