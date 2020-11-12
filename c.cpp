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
          N = 2e5+1;
int n, a[N], p[N];
int node[4*N], lazy[4*N];

void build(int id, int l, int r){
    if (l==r){
        node[id]=0;
        return;
    }
    int m((l+r)/2);
    build(2*id, l, m);
    build(2*id+1, m+1, r);
}

void downtree(int id){
    int t = lazy[id];
    node[2*id]+=t;
    node[2*id+1]+=t;
    lazy[2*id]+=t;
    lazy[2*id+1]+=t;
    lazy[id]=0;
    return;
}

void update(int id, int l, int r, int u){
    if (r<u) return;
    if (l>=u){
        ++node[id];
        ++lazy[id];
        return;
    }
    downtree(id);
    int m((l+r)/2);
    update(2*id, l, m, u);
    update(2*id+1, m+1, r, u);
    node[id]=max(node[2*id], node[2*id+1]);
}

int get(int id, int l, int r, int u){
    if (r<u||l>u) return 0;
    if (l==u&&u==r) return node[id];
    downtree(id);
    int m((l+r)/2);
    return get(2*id, l, m, u)+get(2*id+1, m+1, r, u);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    cin >> n;
    FOR(n) cin >> a[i+1];
    FOR(n) cin >> p[i+1];

    build(1, 1, n);
    FOR(i, 1, n+1){
        int pos(p[i]+get(1, 1, n, p[i])), tpos(p[i]+get(1, 1, n, pos));
        while(pos != tpos){
            pos=tpos;
            tpos=p[i]+get(1, 1, n, pos);
        }
        update(1, 1, n, tpos);
        cout << a[tpos] << " ";
    }
}