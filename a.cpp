#include<bits/stdc++.h>

using namespace std;

#define ar array
#define vt vector
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ii pair<int, int>
#define vii vt<ii>
#define vvii vt<vii>
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

const int oo = 1e9;
vvii G;
vi d;

void dijkstra(){
    int n = G.size();
    priority_queue<ii, vii, greater<ii>> pq;
    pb.push(ii(0, 1));

    while(pq.size()){
        int u = pq.top().se,
            du = pq.top().fi;
        pq.pop();
        if (du!=d[u]) continue;

        FOR(i, G[u].size()){
            int v = G[u][i].se,
                uv = G[u][i].fi;
            if (d[v] > du+uv) d[v] = du+uv, pq.push({d[v], v});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    int n, m;
    G = vvii(n+1);
    d = vi(n+1, oo);
    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        G[u].pb({w, v});
        G[v].pb({w, u});
    }
    dijkstra();
}