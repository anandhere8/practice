#include <bits/stdc++.h>

using namespace std;

int main(){
	auto test = [&](){
		long long r, c;
		cin >> r >> c;
		if(c >= r){
			long long d = 1;
			long long res = 0;
			if(c % 2){
				res = c * c, d = -1;
				r--;
			}
			else{
				c--;
				res = c * c, d = 1; 
			}
			res += r * d;
			cout << res;
		}
		else{
			long long res = 0;
			long long d = 1;
			if(r % 2){
				r--, d = 1;
			}
			else{
				c--;
				d = -1;
			}
			res = r * r + c * d;
			cout << res;
		}
	};
	long long tt;
	cin >> tt;
	while(tt--){
		test();
		cout << endl;
	}
	return 0;
}