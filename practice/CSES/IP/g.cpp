#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	auto test = [&](int n){
		int ans = 4 * (12 + 10 * (n - 4)) + (n - 4) * (n - 4) * 8;
		long long num = n * 1ll * n;
		cout << num * (num - 1) / 2 - ans / 2	;
	};
	for(int i = 1; i <= n; i++){
		test(i);
		cout << endl;
	}
	return 0;
}