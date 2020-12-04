#include<bits/stdc++.h>

#define EB emplace_back
#define int long long
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

const int mod = 998244353;
int power(int a, int b){
  if(b == 0) return 1;
  int ans = power(a, b / 2);
  ans = (ans % mod * ans % mod) % mod;
  if(b % 2) ans = (ans * a) % mod;
  return ans;
}

int gcdExtended(int a, int b, int* x, int* y); 
  
// Function to find modulo inverse of a 
int modInverse(int a, int m) 
{ 
    int x, y; 
    int g = gcdExtended(a, m, &x, &y); 
    if (g != 1) 
        printf("Inverse doesn't exist"); 
    else 
    { 
        // m is added to handle negative x 
        int res = (x % m + m) % m; 
        return res;
    } 
} 
  
// C function for extended Euclidean Algorithm 
int gcdExtended(int a, int b, int* x, int* y) 
{ 
    // Base Case 
    if (a == 0)  
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    int x1, y1; // To store results of recursive call 
    int gcd = gcdExtended(b % a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b / a) * x1; 
    *y = x1; 
  
    return gcd; 
} 

void test_case(){
  int n; cin >> n;
  int nm = 2;
  for(int i = 3; i <= n; i++){
    nm *= min(i - 2, n + 2 - i);
  }
  
  int num = power(2, nm) % mod;
  int ans = modInverse(num, mod);
  //if(n <= 3) n--;
  cout << (ans) % mod;
}

int32_t main(){
	IOS;
	int tt = 1; 
  //cin >> tt;
	while(tt--){
    test_case();
    cout << endl;
	}
	return 0;
}
