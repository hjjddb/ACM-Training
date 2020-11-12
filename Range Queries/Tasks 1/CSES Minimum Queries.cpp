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
#define F_OR(i, a, b, s) for (int i=(a); (s)>0? i<(b) : i>(b); i+=(s))
#define F_OR1(n) F_OR(i, 0, n, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for(auto& x: a)

const int N = 2e5+1;
int n, q, a[N], node[4*N];

void build(int id, int l, int r){
    if (l == r){
        node[id] = a[l];
        return;
    }
    int m=(l+r)/2;
    build(2*id, l, m);
    build(2*id+1, m+1, r);
    node[id] = min(node[2*id], node[2*id+1]);
}

int query(int id, int l, int r, int u, int v){
    if (u>r || v<l) return INT_MAX;
    if (u<=l && v>=r) return node[id];
    int m=(l+r)/2;
    return min(query(2*id, l, m, u, v), query(2*id+1, m+1, r, u, v));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    cin >> n >> q;
    FOR(i, 1, n+1) cin >> a[i];
    build(1, 1, n);
    while(q--){
        int l, r; cin >> l >> r;
        cout << query(1, 1, n, l, r) << '\n';
    }
}