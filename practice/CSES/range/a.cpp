#include <bits/stdc++.h>
 
using namespace std;
 template<class Q,
           Q (*merge)(Q, Q),
           Q (*identity)(),
           class L,
           L (*composite)(L, L),
           L (*identity_action)(int, int),
           Q (*act)(L, Q)>
 struct lazy_segment_tree_base{
   Q query(int p){ // O(log n)
     assert(0 <= p && p < n);
     p += size;
     for(int i = log; i >= 1; -- i) push(p >> i);
     return tree[p];
   }
   Q query(int l, int r){ // O(log n)
     assert(0 <= l && l <= r && r <= n);
     if(l == r) return identity();
     l += size, r += size;
     for(int i = log; i >= 1; -- i) {
       if(l >> i << i != l) push(l >> i);
       if(r >> i << i != r) push(r - 1 >> i);
     }
     Q sml = identity(), smr = identity();
     for(; l < r; l >>= 1, r >>= 1){
       if(l & 1) sml = merge(sml, tree[l ++]);
       if(r & 1) smr = merge(tree[-- r], smr);
     }
     return merge(sml, smr);
   }
   Q query_all(){ return tree[1]; } // O(1)
   void set(int p, Q x){ // O(log n)
     assert(0 <= p && p < n);
     p += size;
     for(int i = log; i >= 1; -- i) push(p >> i);
     tree[p] = x;
     for(int i = 1; i <= log; ++ i) refresh(p >> i);
   }
   void update(int p, L f){ // O(log n)
     assert(0 <= p && p < n);
     p += size;
     for(int i = log; i >= 1; -- i) push(p >> i);
     tree[p] = act(f, tree[p]);
     for(int i = 1; i <= log; ++ i) refresh(p >> i);
   }
   void update(int l, int r, L f){ // O(log n)
     assert(0 <= l && l <= r && r <= n);
     if(l == r) return;
     l += size, r += size;
     for(int i = log; i >= 1; -- i){
       if(l >> i << i != l) push(l >> i);
       if(r >> i << i != r) push(r - 1 >> i);
     }
     int l2 = l, r2 = r;
     for(; l < r; l >>= 1, r >>= 1){
       if(l & 1) apply(l ++, f);
       if(r & 1) apply(-- r, f);
     }
     l = l2, r = r2;
     for(int i = 1; i <= log; ++ i){
       if(l >> i << i != l) refresh(l >> i);
       if(r >> i << i != r) refresh(r - 1 >> i);
     }
   }
   template<class G> int max_pref(int l, G g){ // O(log n)
     assert(0 <= l && l <= n), assert(g(identity()));
     if(l == n) return n;
     l += size;
     for(int i = log; i >= 1; -- i) push(l >> i);
     Q sm = identity();
     do{
       while(~l & 1) l >>= 1;
       if(!g(merge(sm, tree[l]))){
         while(l < size){
           push(l);
           l = l << 1;
           if(g(merge(sm, tree[l]))) sm = merge(sm, tree[l ++]);
         }
         return l - size;
       }
       sm = merge(sm, tree[l]);
       ++ l;
     }while((l & -l) != l);
     return n;
   } // f(sum[l, r)) is T, T, ..., T, F, F, ..., F, returns max r with T
   template<class G> int min_suff(int r, G g){ // O(log n)
     assert(0 <= r && r <= n), assert(g(identity()));
     if(r == 0) return 0;
     r += size;
     for(int i = log; i >= 1; -- i) push(r - 1 >> i);
     Q sm = identity();
     do{
       -- r;
       while(r > 1 && r & 1) r >>= 1;
       if(!g(merge(tree[r], sm))){
         while(r < size){
           push(r);
           r = r << 1 | 1;
           if(g(merge(tree[r], sm))) sm = merge(tree[r --], sm);
         }
         return r + 1 - size;
       }
       sm = merge(tree[r], sm);
     }while((r & -r) != r);
     return 0;
   } // f(sum[l, r)) is F, F, ..., F, T, T, ..., T, returns min l with T
   int n, size, log;
   vector<Q> tree;
   vector<L> lazy;
   void refresh(int i){ tree[i] = merge(tree[i << 1], tree[i << 1 | 1]); }
   void apply(int i, L f){
     tree[i] = act(f, tree[i]);
     if(i < size) lazy[i] = composite(f, lazy[i]);
   }
   void push(int i){
     apply(i << 1, lazy[i]), apply(i << 1 | 1, lazy[i]);
     int h = log - __lg(i);
     lazy[i] = identity_action((i << h) - size, (i + 1 << h) - size);
   }
   lazy_segment_tree_base(): lazy_segment_tree_base(0){}
   lazy_segment_tree_base(int n): lazy_segment_tree_base(vector<Q>(n)){}
   lazy_segment_tree_base(const vector<Q> &v): n((int)v.size()){ // O(n)
     log = __lg(n + 1) + 1, size = 1 << log;
     tree = vector<Q>(size << 1, identity()), lazy = vector<L>(size);
     copy(v.begin(), v.end(), tree.begin() + size);
     for(int i = 1; i < size; ++ i){
       int h = log - __lg(i);
       lazy[i] = identity_action((i << h) - size, (i + 1 << h) - size);
     }
     for(int i = size - 1; i >= 1; -- i) refresh(i);
   }
 };
 using Q = long long; // Monoid (Query Type)
 Q merge(Q x, Q y){ // merges adjacent intervals
   return max(x, y);
 }
 Q identity(){ // Monoid Identity
   return numeric_limits<long long>::min() / 2;
 }
 using L = long long; // Semigroup (Lazy Type)
 L composite(L f, L g){ // composites superset and subset 
   return f + g;
 }
 L identity_action(int l, int r){
   return 0;
 }
 Q act(L f, Q x){ // semigroup action of L on Q, act superset onto subset
   return f + x;
 }
 using lazy_segment_tree = lazy_segment_tree_base<Q, merge, identity, L, composite, identity_action, act>;
 
int main(){
  int n, m;
  cin >> n >> m;
  segment_tree seg(n);
  vector < int > A(n);
  for(int i = 0; i < n; i++){
    cin >> A[i];
    seg.set(i, A[i]);
  }
  while(m--){
    int a, b;
    cin >> a >> b;
    a--;
    cout << seg.query(a, b) << endl;
  }
  return 0;
}