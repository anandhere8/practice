#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
	int n;
	cin >> n;
	cout << n << " ";
	while(n > 1){
		if(n % 2 == 0) n /= 2;
		else{
			n *= 3;
			n++;
		}
		cout << n << " ";
	}
	return 0;
}