#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin >> s;
	int res = 1, tmp = 1;
	int n = (int)s.size();
	for(auto i = 1; i < n; ++ i){
		if(s[i] != s[i - 1]){
			tmp = 0;
		}
		tmp++;
		res = max(res, tmp);
	}
	res = max(res, tmp);
	cout << res;
	return 0;
}