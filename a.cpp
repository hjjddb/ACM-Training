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
int n, m, cnt, low[N], num[N], numChild[N];
bool isArt[N];
vt<vt<int>> G;
vt<ii> bridges;

void dfs(int u, int p){
    low[u] = num[u] = ++cnt;
    EACH(v, G[u]){
        if (!num[v]){
            ++numChild[u];
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        } else {
            if (v != p){
                low[u] = min(low[u], num[v]);
            }
        }
        if (low[u]==num[u]){
            if (numChild[u]>1) isArt[u]=true;
        }
        if (num[u]<low[v]){
            bridges.pb({u, v});
            isArt[u]=true;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    cin >> n >> m;
    G = vt<vt<int>>(n+1);
    FOR(m){
        int u, v;
        cin >> u >> v;
        G[u].pb(v);
        // G[v].pb(u); // if undirected
    }
    FOR(i, 1, n+1) if (!num[i]) dfs(i, -1);
    FOR(i, 1, n+1) cout << i << " " << num[i] << " " << low[i] << '\n';
    EACH(b, bridges) cout << b.fi << " " << b.se << '\n';
    FOR(i,1 , n+1) if (isArt[i]) cout << i << '\n';
}