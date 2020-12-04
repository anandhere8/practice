//|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
//|                      Written By: Anmol_Tomer										  |
//|		  Date: 14-11-2020, at 01-01-40							  |
//|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
//Compile: g++ -std=c++14 -O2 -Wall test.cpp -o test.out
//Debug: g++ -g -std=c++14 -O2 -Wall test.cpp -o test.out
// Problem Link:

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
#define endl "\n"
#define sd(val) scanf("%d", &val)
#define pd(val) printf("%d\n", val)
#define REP(a, b) for (int i = a; i < b; i++)
#define REP1(a, b) for (int i = a; i <= b; i++)
#define frr(i, n) for (int i = 0; i < (n); i++)
#define ss(val) scanf("%s", &val)
#define sull(val) scanf("%llu", &val)
#define sl(val) scanf("%lld", &val)
#define debug(val) printf("check%d\n", val)
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define ff first
#define sc second
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define w(t)  \
    int t;    \
    cin >> t; \
    while (t--)
#define clr(val) memset(val, 0, sizeof(val))
#define what_is(x) cerr << #x << " is " << x << endl;
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

// <=======END OF TEMPLATE=============>
void solve()
{
}
int main()
{
    // OJ;
    FIO;
    ull n, k;
    cin >> n >> k;
    if (n % 2 == 0)
    {
        if (k <= n / 2)
            cout << (2 * k) - 1;
        else
            cout << 2 * (k - (n / 2));
    }
    else
    {
        if (k <= (n + 1) / 2)
            cout << (2 * k) - 1;
        else
            cout << 2 * (k - (n + 1) / 2);
    }
    return 0;
}

//APPROACHING A QUESTION
//+ Think of binary search (max of min etc also if n<=2*10^5)
//+ Think of common dp states (Even if it appears as maths but constraints are small)
//+ Check constraints
//+ Keep calm and enjoy the question
//+ Be sure to remove MOD from binpow (if needed)
//+ Try bidirectional analysis for constructive questions
//+ If given some sequence try thinking of prefix sums
//+ If constraints are too large maybe its simple maths
//+ In questions with binary operations think of bits independently and also the change pattern
//+ If two or more binary operations are given mostly there is a relation between them and an arithmatic operator
