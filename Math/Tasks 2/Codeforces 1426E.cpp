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

int n, a[3], b[3], c[3], d[3], l(INT_MAX), w(0);
bool check[3];

void backtrack(int id){
    FOR(3){
        if (check[i]){
            int tmp=min(c[i], d[(i+2)%3]);
            c[i]-=tmp;
            d[(i+2)%3]-=tmp;
            int tmp1=min(c[i], d[i]);
            c[i]-=tmp1;
            d[i]-=tmp1;
            check[i]=false;
            if (id==2){
                int tmpl=0;
                FOR(k, 3) tmpl+=c[k];
                l=min(l, tmpl);
            } else backtrack(id+1);
            c[i]+=tmp+tmp1;
            d[(i+2)%3]+=tmp;
            d[i]+=tmp1;
            check[i]=true;
        }
    }
}

void solve(){
    cin >> n;
    FOR(3) cin >> a[i];
    FOR(3) cin >> b[i];
    FOR(3) c[i]=a[i], d[i]=b[i];
    memset(check, true, sizeof check);
    backtrack(0);
    FOR(3) w+=min(a[i], b[(i+1)%3]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    solve();
    cout << l << " " << w;
}