#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector < int > A(n);
	for(int i = 0; i < n - 1; i++){
		cin >> A[i];
	}
	cout << n * 1ll * (n + 1) / 2 - accumulate(A.begin(), A.end(), 0LL);
	return 0;
}