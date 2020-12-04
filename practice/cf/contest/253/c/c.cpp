#include<bits/stdc++.h>

using namespace std;

int n, A[105], r1, r2, c1, c2, answer, sum, c;

int check(int r){
  sum = abs(r - r1) + abs(r - r2);
  c = c1;
  for (int i = min(r, r1); i <= max(r, r1); ++i) {
		c = min(c, A[i] + 1);
	}
	for (int i = min(r, r2); i <= max(r, r2); ++i) {
		c = min(c, A[i] + 1);
	}
	sum += abs(c2 - c);
	return sum;
}

int main(){
  freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    scanf("%d", A + i);
  }
  answer = INT_MAX;
  scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
  for(int i = 1; i <= n; i++){
    answer = min(answer, check(i));
  }
  printf("%d\n", answer);
  return 0;
}
