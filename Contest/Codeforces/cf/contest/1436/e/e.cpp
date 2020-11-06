#include<bits/stdc++.h>

using namespace std;

vector < int > seg;

const int nax = 1e5 + 20;

bool ok[nax];

const int cng = 0;

void init(int n){
  seg.resize(4 * n);
  fill(seg.begin(), seg.end(), -1);
}

void update(int root, int l, int r, int idx, int val){
  if(l == r){
    seg[root] = val;
    return;
  }
  int mid = (l + r) / 2;
  if(idx <= mid){
    update(2 * root + cng, l, mid, idx, val);
  }
  else update(2 * root + 1 + cng, mid + 1, r, idx, val);
  seg[root] = min(seg[2 * root + 1 + cng], seg[2 * root + cng]);
}

int query(int root, int l, int r, int x){
  if(l == r){
    return l;
  }
  int mid = (l + r) / 2;
  if(seg[2 * root + cng] < x) return query(2 * root + cng, l, mid, x);
  return query(2 * root + 1 + cng, mid + 1, r, x);
}
  
  


void test_cases(){
  int n;
  scanf("%d", &n);
  int N = n + 5;
  init(n + 5);
  int ss = 1, end = N, root = 1;
  int A[n];
  map < int, int > mp;
  set < int > st;
  int cnt = 0;
  for(int i = 0; i < n; i++){
    scanf("%d", A + i);
    if(A[i] > 1) cnt++;
    st.insert(A[i]);
  }
    
  if(!st.count(1)){
    puts("2");
    return;
  }
  
  if((int)st.size() == 1){
    puts("1");
    return;
  }
  st.clear();
  update(root - cng, ss - cng, end - cng, 0, 1e9);
  for(int i = 0; i < n; i++){
    int l = (mp.count(A[i]) == 1) ? mp[A[i]] : -1;
    l++;
    mp[A[i]] = i;
    int mex = query(root - cng, ss - cng, end - cng, l);
    ok[mex] = true;
    st.insert(mex);
    update(root - cng, ss - cng, end - cng, A[i], i);
  }
  for(int i = 0; i < n; i++){
    int mex = query(root - cng, ss - cng, end - cng, i);
    ok[mex] = true;
    st.insert(mex);
  }
  for(int i = 1; i <= n + 2; i++){
    if(!st.count(i)){
      printf("%d", i);
      return;
    }
  }
}

int main(){
  int tt = 1; 
  //scanf("%d", &tt);
  while(tt--){
    test_cases();
    puts("");
  }
  return 0;
}
