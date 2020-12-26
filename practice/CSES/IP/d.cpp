#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector < int > A(n);
	int val = 0;
	long long res = 0;
	for(int i = 0; i < n; i++){
		cin >> A[i];
		val = max(A[i], val);
		res += max(val - A[i], 0);
	}
	cout << res;
	return 0;
}