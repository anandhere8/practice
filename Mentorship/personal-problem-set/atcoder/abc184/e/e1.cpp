#include <bits/stdc++.h>

using namespace std;

int solve(int A[], int n)
{
    for(int i = 29; i >= 0; i--)
    {
        int mx = 0;
        int id = -1;
        for(int j = 0; j < n; j++)
        {
            if(A[j] & (1 << i))
            {
                if(mx < A[j])
                {
                    mx = A[j];
                    id = j;
                }
            }
        }
        if(id == -1)
            continue;
        for(int j = 0; j < n; j++)
        {
            if((A[j] & (1 << i)) and id != j)
            {
                A[j] ^= mx;
            }
        }
    }
    int sol = 0;
    for(int i = 0; i < n; i++)
    {
        //cout << A[i] << " ";
        sol ^= A[i];
    }
    return sol;
}

int main(){
  int n; cin >> n;
  int A[n];
  for(int i = 0; i < n; i++) cin >> A[i];
  cout << solve(A, n);
}
  
  
  
  
  
  
  
  
  
