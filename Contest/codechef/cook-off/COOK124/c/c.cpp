#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pie (3.141592653589)
using namespace std;

const int N = 2e5 + 10;

int xx;
int n, K;
vector<int> nums;
int dp[10][1 << 10];
int store[1 << 10];
int val;

const int INF = 1e6 + 10;

int solve(int k, int mask)
{
	if(k == 0)
	{
		if(mask != val - 1)
			return INF;
		return 0;
	}
	if(mask == (val - 1))
	{
		return INF;
	}
	if(dp[k][mask] != -1)
	{
		return dp[k][mask];
	}
	int sol = INF;
	for(int i = 1; i < val; i++)
	{
		if((mask & i) != 0)
			continue;
		int sum = store[i];
		sol = min(sol, sum + solve(k - 1, mask | i));
	}
	return dp[k][mask] = sol;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout.precision(10);
	
	int T;
	cin >> T;
	while(T--)
	{
		nums.clear();
		int k, x;
		cin >> k >> x;
		xx = k;
		for(int i = 2; i <= sqrt(x); i++)
		{
			int aa = 1;
			while(x % i == 0)
			{
				aa *= i;
				x /= i;
			}
			nums.push_back(aa);
		}
		if(x > 1)
		{
			nums.push_back(x);
		}
		if((int) nums.size() > k)
		{
			K = (int) nums.size();
			val = (1 << K);
			assert(K < 10);
			for(int i = 1; i < val; i++)
			{
				store[i] = 1;
				for(int j = 0; j < K; j++)
				{
					if(i & (1 << j))
					{
						store[i] *= nums[j];
					}
				}
			}
			memset(dp, -1, sizeof dp);
			cout << solve(k, 0) << "\n";
			continue;
		}
		int sum = 0;
		for(int i : nums)
		{
			sum += i;
		}
		sum += k - (int) nums.size();
		cout << sum << "\n";
	}
	
	
	return 0;
}
