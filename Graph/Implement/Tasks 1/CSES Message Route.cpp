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

const int N = 1e5+1;
int n, m, f[N];
vt<int> d[N];
bool vs[N];
vt<int> res;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    memset(vs, false, sizeof vs);
    cin >> n >> m;
    FOR(i, 1, n+1) f[i]=INT_MAX;
    FOR(m){
        int u, v;
        cin >> u >> v;
        d[u].pb(v);
        d[v].pb(u);
    }
    queue<int> q;
    q.push(1);
    vs[1] = true;
    f[1] = 1;
    while(q.size()){
        int u=q.front();
        q.pop();
        EACH(v, d[u]){
            if (vs[v]) continue;
            q.push(v);
            f[v] = min(f[v], f[u]+1);
            vs[v] = true;
        }
    }
    if (f[n] == INT_MAX) cout << "IMPOSSIBLE\n";
    else {
        cout << f[n] << '\n';
        vt<int> ans;
        ans.pb(n);
        int u=n;
        while(f[u]>1){
            EACH(v, d[u]){
                if(f[v]==f[u]-1){
                    u=v;
                    ans.pb(u);
                    break;
                }
            }
        }
        FOR(ans.size()) cout << ans[ans.size()-1-i] << " ";
    }
}