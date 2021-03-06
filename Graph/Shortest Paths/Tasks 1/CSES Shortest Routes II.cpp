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
const ll oo = 1e18;

template<class T1, class T2> ostream &operator <<(ostream &cout, pair<T1, T2> x){
    cout << "(" << x.fi << "," << x.se << ")";
    return cout;
}

template<class T> void read1(T &x){
    FOR(x.size()) cin >> x[i];
}

template<class T> void read2(vt<T> &x){
    FOR(x.size()) read1(x[i]);
}	
template<class T> void print1(T &x){
    EACH(xi, x) cout << xi << ' ';
    cout << '\n';
}

template<class T> void print2(vt<T> &x){
    FOR(x.size()){
        print1(x[i]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    int n, m, q;
    cin >> n >> m >> q;
    vvl d(n, vl(n, oo));
    FOR(m){
        int u, v, w;
        cin >> u >> v >> w, --u, --v;
        d[u][v]=min(d[u][v], 1LL*w);
        d[v][u]=min(d[v][u], 1LL*w);
    }
    FOR(n) d[i][i]=0;
    FOR(k, n){
        FOR(i, n){
            FOR(j, n) d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
        }
    }
    while(q--){
        int u, v;
        cin >> u >> v, --u, --v;
        cout << (d[u][v]>=oo?-1:d[u][v]) << '\n';
    }
}