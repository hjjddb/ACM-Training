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

const int N = 5e3+1;
int n, m, ans=1, c[N];
vt<ii> d[N];
bool vs[N];
set<int> st;

void dfs(int u){
    FOR(d[u].size()){
        int id=d[u][i].fi, v=d[u][i].se;
        if (st.find(v)!=st.end()){
            ans=2;
            c[id]=2;
        } else {
            c[id]=1;
            if (!vs[v]) {
                vs[v]=true;
                st.insert(v);
                dfs(v);
                st.erase(v);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    memset(vs, false, sizeof vs);
    cin >> n >> m;
    FOR(m){
        int u, v;
        cin >> u >> v;
        d[u].pb(ii(i, v));
    }
    FOR(n) 
        if(!vs[i+1]){
            st.insert(i+1);
            vs[i+1]=true;
            dfs(i+1);
            st.erase(i+1);
        }
    cout << ans << '\n';
    FOR(m) cout << c[i] << " ";
}