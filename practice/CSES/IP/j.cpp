#include <bits/stdc++.h>

using namespace std;

// Requires barrett
long long pow_mod(long long x, long long n, int m){
	assert(0 <= n && 1 <= m);
	if(m == 1) return 0;
	barrett bt((unsigned int)(m));
	unsigned int r = 1, y = x % m;
	if(y < 0) y += m;
	for(; n; y = bt.mul(y, y), n >>= 1) if(n & 1) r = bt.mul(r, y);
	return r;
}

int main(){
	int n;
	cin >> n;
	const int mod = 1e9 + 7;
	cout << pow_mod(2, n, mod);
	return 0;
}