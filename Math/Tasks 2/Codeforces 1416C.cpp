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

const int N = 3e5+1;
int n;
ll res[2][31], ans[2];
vt<int> a;

void dfs(int k, vt<int> v){
    if (k==-1 || !v.size()) return;
    ll res0(0), res1(0);
    vt<int> ne[2]; 
    // gurantee if xor bit k with x, y in the same vector, 
    // if (x[k] && !y[k]) // in binary present
    // -> x^(1<<k) < y^(1<<k) 
    EACH(x, v){
        if (x & (1<<k)){ // x[k] in binary = 1 -> xor 1<<k will decrease x 
            ne[1].pb(x);
            ++res1; // number of element would be decreased if use bit 1 at k
            res[1][k]+=res0; // bcuz a[i] would be decreased, it would be smaller than res0 elements in range [0, i)
        } else {
            ne[0].pb(x);
            ++res0;
            res[0][k]+=res1;
        }
    }
    dfs(k-1, ne[0]);
    dfs(k-1, ne[1]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    cin >> n;
    FOR(n){
        int x; cin >> x;
        a.pb(x);
    }
    dfs(30, a);
    FOR(31){
        if (res[1][i]<res[0][i]){
            ans[1] += 1<<i;
        }
        ans[0] += min(res[1][i], res[0][i]);
    }
    FOR(2) cout<< ans[i] << " "; 
}