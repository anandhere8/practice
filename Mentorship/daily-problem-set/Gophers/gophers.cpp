#include <bits/stdc++.h>

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
  ans = nums[0];
  int lcm_ = mods[0];
  //for(int i = 0; i < t; i++){
    //cout << nums[i] << " " << mods[i] << endl;
  //}
  //return 0;
  for(int i = 1; i < t; i++)
  {
      auto pom = ex_GCD(lcm_, mods[i]);
      int x1 = pom.x;
      int d = pom.d;
      if((nums[i] - ans) % d != 0) {
        cerr << "No solutions" << endl;
        return 0;
      }
      ans = normalize(ans + x1 * (nums[i] - ans) / d % (mods[i] / d) * lcm_, lcm_ * mods[i] / d);
      lcm_ = LCM(lcm_, mods[i]);
  }
  return ans;
}


int main(){
  int t, n, m;
  cin >> t >> n >> m;
  int nums[] = {5, 7, 9, 11, 13, 16, 17}, mods[7];
  int ans;
  for(int foo = 0; foo < t ; foo++){
    for(int ii = 0; ii < 7; ii++){
      int sum = 0;
      for(int i = 0; i < 18; i++){
        cout << nums[ii] << " ";
      }
      cout << endl;
      for(int i = 0; i < 18; i++){
        int x; cin >> x;
        sum += x;
        sum %= nums[ii];
      }
      mods[ii] = sum;
    }
    ans = CRT(7, mods, nums);
    cout << ans << endl;
    int ver; cin >> ver;
    if(ver == -1){
      exit(0);
    }
  }
  return 0;
}
