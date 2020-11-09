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
int n, a[N], q, t;
ll node[4*N], lazy[4*N];

void build(int id, int l, int r){
    if (l==r){
        node[id] = 1LL*a[l];
        return;
    } 
    int m=(l+r)/2;
    build(2*id, l, m);
    build(2*id+1, m+1, r);
    node[id] = node[2*id]+node[2*id+1];
}

void downtree(int id, int l, int r){
    ll tmp = lazy[id]/(r-l+1);
    int m=(l+r)/2;
    node[2*id] += 1LL*(m-l+1)*tmp;
    node[2*id+1] += 1LL*(r-m)*tmp;
    lazy[2*id] += 1LL*(m-l+1)*tmp;
    lazy[2*id+1] += 1LL*(r-m)*tmp;
    lazy[id] = 0;
}

void update(int id, int l, int r, int x, int y, ll k){
    if (l>y || r<x) return;
    if (l>=x && r<=y){
        node[id] += (r-l+1)*1LL*k;
        lazy[id] += (r-l+1)*1LL*k;
        return;
    }
    downtree(id, l, r);
    int m=(l+r)/2;
    update(2*id, l, m, x, y, k);
    update(2*id+1, m+1, r, x, y, k);
    node[id] = node[2*id]+node[2*id+1];
}

ll get(int id, int l, int r, int x){
    if (l>x || r<x) return 0;
    if (l==x && x==r) return node[id];
    downtree(id, l, r);
    int m=(l+r)/2;
    return 1LL*get(2*id, l, m, x)+get(2*id+1, m+1, r, x);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    cin >> n >> q;
    FOR(n) cin >> a[i+1];
    build(1, 1, n);
    while(q--){
        cin >> t;
        if (t == 1){
            ll x, y, z; 
            cin >> x >> y >> z;
            update(1, 1, n, x, y, z);
        }
        else{
            ll x;
            cin >> x;
            cout << get(1, 1, n, x) << "\n";
        }
    }
}