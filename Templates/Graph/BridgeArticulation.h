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

struct UndirectedDfs{
    vt<int> low, num, parent;
    vt<bool> articulation;
    int counter, root, children;

    vt<ii> bridges;
    vt<int> cuts;

    UndirectedDfs() : low(V, 0), num(V, -1), parent(V, 0), articulation(V, false), counter(0), children(0) {
        FOR(V) if (num[i]==-1){
            root=i, children=0;
            dfs(i);
        }
    }

    private:
        void dfs(int u){
            low[u] = num[u] = counter++;
            EACH(v: G[u]){
                if (num[v]==-1){
                    parent[v]=u;
                    if (u==root) children++;
                    dfs(v);
                    if (low[v]>=num[u]) articulation[u]=true;
                    if (low[v]>num[u]) bridges.pb(ii(u, v));
                    low[u]=min(low[u], low[v]);
                } else if (v!=parent[u])
                    low[u]=min(low[u], num[v]);
            }
        }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

}