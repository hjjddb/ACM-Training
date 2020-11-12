#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ar array
#define vt vector
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ll long long
#define ld long double
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second
#define FORIT(i, s) for (auto it=(s.begin()); it!=(s.end()); ++it)
#define F_OR(i, a, b, s) for (int i=(a); (s)>0? i<(b) : i>(b); i+=(s))
#define F_OR1(n) F_OR(i, 0, n, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for(auto& x: a)

const int d4x[] = {-1, 0, 1, 0},
          d4y[] = {0, -1, 0, 1},
          d8x[] = {-1, -1, -1, 0, 0, 1, 1, 1},
          d8y[] = {-1, 0, 1, -1, 1, -1, 0, 1}, 
          N = 2e5;
int n, m, q, node[2*N], lazy[2*N], h;

void apply(int p, int val){
    node[p]+=val;
    if (p<n) lazy[p]+=val;
}

void build(int p){
    // update to all parent of p
    while (p>1){
        p>>=1;
        node[p] = max(node[p<<1], node[p<<1|1])+lazy[p];
    }
}

void push(int p){
    // push lazy from parent of p
    FOR(s, h, 0, -1){
        int id=p>>s;
        if (lazy[id]){
            apply(id<<1, lazy[id]);
            apply(id<<1|1, lazy[id]);
            lazy[id]=0;
        }
    }
}

void update(int l, int r, int val){
    // update node[l, r)+=val 
    l+=n, r+=n;
    int l0(l), r0(r);
    for(; l<r; l>>=1, r>>=1){
        if (l&1) apply(l++, val);
        if (r&1) apply(--r, val);
    }
    build(l0); 
    build(r0-1);
}

int query(int l, int r){
    int res = INT_MIN;
    l+=n, r+=n;
    push(l);
    push(r-1);
    for(; l<r; l>>=1, r>>=1){
        if (l&1) res=max(res, node[l++]);
        if (r&1) res=max(res, node[--r]);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    cin >> n >> m;
    h = sizeof(int)*8- __builtin_clz(n);
    while(m--){
        int u, v, k;
        cin>> u >> v >> k;
        update(u-1, v, k);
    }
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << query(l-1, r) << "\n";
    }
}