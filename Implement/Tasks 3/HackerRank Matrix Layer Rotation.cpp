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
#define vi vt<int>
#define vl vt<ll>
#define vvi vt<vi>
#define vvl vt<vl>
#define vii vt<ii>
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
          d8y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void read(vi &x){
    FOR(x.size()) cin >> x[i];
}

void read(vvi &x){
    FOR(x.size()) read(x[i]);
}

void print(vi &x){
    EACH(xi, x) cout << xi << " ";
}

void print(vvi &x){
    FOR(x.size()){
        print(x[i]);
        cout << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    int n, m, r;
    cin >> n >> m >> r;
    vvi a(n, vi(m));
    read(a);
    int mni(0), mnj(0), mxi(n-1), mxj(m-1), k(0);
    vi v[(min(n, m)>>1) + 1];
    while(mni<=mxi&&mnj<=mxj){
        FOR(i, mni, mxi) v[k].pb(a[i][mnj]);
        FOR(j, mnj, mxj) v[k].pb(a[mxi][j]);
        FOR(i, mxi, mni, -1) v[k].pb(a[i][mxj]);
        FOR(j, mxj, mnj, -1) v[k].pb(a[mni][j]);
        ++mni, ++mnj, ++k;
        --mxi, --mxj;
    }
    vi nv[(min(n, m)>>1)+1];
    FOR(ik, k){
        int sz = v[ik].size();
        FOR(i, sz-r%sz, sz) nv[ik].pb(v[ik][i]);
        FOR(i, sz-r%sz) nv[ik].pb(v[ik][i]);
    }
    vvi b(n, vi(m));
    int li(n), lj(m);
    k=0;
    mni=0, mxi=n-1, mnj=0, mxj=m-1;
    while(mni<=mxi&&mnj<=mxj){
        int id(0);
        FOR(i, mni, mxi) a[i][mnj]=nv[k][id++];
        FOR(j, mnj, mxj) a[mxi][j]=nv[k][id++];
        FOR(i, mxi, mni, -1) a[i][mxj]=nv[k][id++];
        FOR(j, mxj, mnj, -1) a[mni][j]=nv[k][id++];
        ++mni, ++mnj, ++k;
        --mxi, --mxj;
    }
    print(a);
}