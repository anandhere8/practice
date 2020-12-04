#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pie (3.141592653589)
using namespace std;

const int N = 2e5 + 10;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout.precision(10);
	int T = 1;
	cin >> T;
	while(T--)
	{
		int n;
		long long w;
		cin >> n >> w;
		vector<long long> a(n);
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		vector<int> order(n);
		iota(order.begin(), order.end(), 0);
		sort(order.begin(), order.end(), [&](int i, int j)
		{
			return a[i] < a[j];
		});
		vector<int> sol;
		bool can = true;
		int p = -1;
		for(int i = 0; i < n; i++)
		{
			if(a[order[i]] > w)
				break;
			p = i;
		}
		long long sum = 0;
		if(p == -1)
			can = false;
		for(int i = p; i >= 0; i--)
		{
			sum += a[order[i]];
			sol.push_back(order[i]);
			if(sum > w)
			{
				can = false;
				break;
			}
			if(sum >= (w + 1) / 2)
				break;
		}
		if(sum < ((w + 1) / 2))
		{
			can = false;
		}
		if(!can)
		{
			cout << "-1\n";
			continue;
		}
		cout << sol.size() << "\n";
		for(auto i : sol)
		{
			cout << i + 1 << " ";
		}
		cout << "\n";
	}
	return 0;
}
