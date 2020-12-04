#include<bits/stdc++.h>

using namespace std;

int main(){
  int n, m, q, row[1005], col[1005], A[1005][1005], x, y;
  char s;
  scanf("%d%d%d", &n, &m, &q);
  for(int i = 0; i < n; i++){
    row[i] = i, col[i] = i;
    for(int j = 0; j < m; j++){
      row[j] = j, col[j] = j;
      scanf("%d", &A[i][j]);
    }
  }
  while(q--){
    scanf("%c%d%d", &s, &x, &y);
    x--, y--;
    if(s == 'g'){
      printf("%d\n", A[row[x]][col[y]]);
    }
    else{
      if(s == 'r'){
        swap(row[x], row[y]);
      }
      else if (s == 'c') {
        swap(col[x], col[y]);
      }
    }
    scanf("%c", &s);
  }
  return 0;
}
