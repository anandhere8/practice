#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	long long sum = n * 1ll * (n + 1) / 2;
	if(sum % 2){
		cout << "NO";
		return 0;
	}
	cout << "YES" << endl;
	sum /= 2;
	vector < int > tmpv(n);
	vector < int > res, a;
	iota(tmpv.begin(), tmpv.end(), 1);
	long long sm = 0;
	for(int i = n - 1; i >= 0; i--){
		int &x = tmpv[i];
		if(sm + x <= sum){
			sm += x;
			res.push_back(x);
		}
		else{
			a.emplace_back(x);
		}
	}
	assert(sm == sum);
	cout << (int)res.size() << endl;
	for(auto x : res){
		cout << x << " ";
	}
	cout << endl;
	cout << (int)a.size() << endl;
	for(auto x : a){
		cout << x << " ";
	}
	return 0;
}