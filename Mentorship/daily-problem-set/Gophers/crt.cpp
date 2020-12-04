#include<bits/stdc++.h>

using namespace std;

inline long long LCM(long long a, long long b) { return a / __gcd(a, b) * b; }
inline long long normalize(long long x, long long mod) { x %= mod; if (x < 0) x += mod; return x; }
struct GCD_type { long long x, y, d; };
GCD_type ex_GCD(long long a, long long b)
{
    if (b == 0) return {1, 0, a};
    GCD_type pom = ex_GCD(b, a % b);
    return {pom.y, pom.x - a / b * pom.y, pom.d};
}

long long CRT(int t, int *nums, int *mods){
  long long ans;
  ans = mods[0];
  int lcm_ = nums[0];
  for(int i = 1; i < t; i++)
  {
      auto pom = ex_GCD(lcm_, nums[i]);
      int x1 = pom.x;
      int d = pom.d;
      if((mods[i] - ans) % d != 0) return cerr << "No solutions" << endl, 0;
      ans = normalize(ans + x1 * (mods[i] - ans) / d % (nums[i] / d) * lcm_, lcm_ * nums[i] / d);
      lcm_ = LCM(lcm_, nums[i]);
  }
  return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int nums[n + 1], mods[n + 1];
    for(int i = 0; i < n; i++){
      cin >> nums[i];
    }  
    for(int i = 0; i < n; i++){
      cin >> mods[i];
    }
    cout << CRT(n, nums, mods);
    return 0;
}
