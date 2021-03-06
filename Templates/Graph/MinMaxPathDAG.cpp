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
          d8y[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const ll oo = LLONG_MAX;
int n, m, cnt;
vt<vt<ii>> G; // G is a DAG
vt<bool> vs;
vt<int> topo;
vt<ll> d;

void dfs(int u){
    vs[u]=true;
    // cout << u << '\n';
    EACH(e, G[u]){
        int w(e.fi), v(e.se);
        if (!vs[v]){
            dfs(v);
        }
    }
    topo[--cnt]=u;
}

void topoSort(){
    topo = vt<int>(n, 0);
    cnt = n;
    vs = vt<bool>(n+1, false);
    FOR(i, 1, n+1){
        if (!vs[i]) dfs(i);
    } 
}

ll shortestPathDAG(vt<vt<ii>> G){
    vt<ll> d(n+1, oo);
    d[1] = 0LL;
    EACH(u, topo){
        EACH(e, G[u]){
            int w(e.fi), v(e.se);
            d[v] = min(d[v], d[u]+w);
        }
    }
    return d[n];
}

ll longestPathDAG(vt<vt<ii>> G){
    vt<vt<ii>> G_ = G;
    FOR(i, 1, n+1){
        EACH(e, G_[i])
            e.fi*=-1;
    }
    return -1*shortestPathDAG(G_);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    cin >> n >> m;
    G = vt<vt<ii>>(n+1);
    vs = vt<bool>(n+1, false);
    FOR(m){
        int u, v, w;
        cin >> u >> v >> w;
        G[u].pb(ii(w, v));
    }
    topoSort();
    cout << shortestPathDAG(G) << " " << longestPathDAG(G);
}