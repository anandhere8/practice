#include <bits/stdc++.h>

using namespace std;

int main(){
	auto test = [&](){
		int n, m;
		cin >> n >> m;
		if(n > m) swap(n, m);
		if(2 * n < m){
			cout << "NO";
		}
		else{
			if((n + m) % 3 == 0){
				cout << "YES";
			}
			else{
				cout << "NO";
			}
		}
	};
	int tt;
	cin >> tt;
	while(tt--){
		test();
		cout << endl;
	}
	return 0;
}