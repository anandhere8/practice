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
  int n = 3;
  int x = random(10, 200);
  cout << n << " " << x;
  cout << endl;
  return 0;
}
	
