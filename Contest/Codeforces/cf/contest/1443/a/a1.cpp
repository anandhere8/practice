#include<bits/stdc++.h>

using namespace std;

void Encrypt(char T[]){
  for(int i = 0; T[i] != '\0'; i+= 2)
  if(T[i] == 'A' || T[i] == 'E')
    T[i] = '#';
    else if(islower(T[i])) T[i] = toupper(T[i]);
    else T[i] = '@';
  }

int main(){
  char text[] = "SavVE NaTuRE";
  Encrypt(text);
  cout << text;
  return 0;
}
