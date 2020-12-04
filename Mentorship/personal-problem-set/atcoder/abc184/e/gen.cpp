#include <bits/stdc++.h>

using namespace std;

// constraints
const int lenl = 1, lenr = 5; // range of size of array
const int valuel = 1, valuer = 5; // range of value of array


int random(int a, int b){
  return (rand() % (b - a + 1) + a);
}

int main(int argc, char *argv[]){
  srand(atoi(argv[1]));
  int n = 5;
  int m = 5;
  cout << n << " " << m << endl;
  
  vector < char > A;
  
  for(int i = 0; i < 26; i++){
    A.push_back('a' + i);
    A.push_back('.');
    A.push_back('#');
  }
  A.push_back('.');
    A.push_back('#');A.push_back('.');
    A.push_back('#');A.push_back('.');
    A.push_back('#');
  done :
  int si = random(1, n), sj = random(1, m);
  int gi = random(1, n), gj = random(1, m);
  if(si == gi && sj == gj){
    goto done;
  }
  for(int i = 0; i < n; i++, cout << endl){
    for(int j = 0; j < m; j++){
      if(i == si - 1 && j == sj - 1){
        cout << "S";
        continue;
      }
      if(i == gi - 1 && j == gj - 1){
        cout << "G";
        continue;
      }
      int x = random(1, 200);
      cout << A[x % 80];// << " ";
    }
    //cout << endl;
  }
  return 0;
}
	
