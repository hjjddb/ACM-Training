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
          N = 1e5+1;
int n, m, a[10][N], ans, p[10][N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    cin >> n >> m;
    FOR(m)
        FOR(j, n){
            cin >> a[i][j];
            p[i][a[i][j]] = j;
        }

    vt<ii> v;
    v.pb({0, n-1});
    FOR(v.size()){
        FOR(j, 1, m){
            ii x = v[i];
            int s = p[j][a[0][x.fi]];
            int cnt(0);
            while(a[0][x.fi+cnt]==a[j][s+cnt]){
                ++cnt;
                if (max(x.fi, s)+cnt>=n) break;
            }
            if (x.se>x.fi+cnt-1){
                v[i] = ii(x.fi, x.fi+cnt-1);
                v.pb({x.fi+cnt, x.se});
            }
        }
    }
    ll ans(0);
    EACH(x, v) ans += 1LL*(x.se-x.fi+1)*(x.se-x.fi+2)/2;
    cout << ans; 
}