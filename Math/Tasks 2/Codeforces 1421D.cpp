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

const int d6x[] = {1, 1, 0, -1, -1, 0},
          d6y[] = {0, 1, 1, 0, -1, -1};
int c[7];
map<ii, int> mp;

void init(){
    FOR(i, 6){
        ii u = ii(d6x[i], d6y[i]);
        mp[u]=min(c[i], c[(i+1)%6]+c[(i+5)%6]);
    }
    mp[ii(1, -1)]=mp[ii(1, 0)]+mp[ii(0, -1)];
    mp[ii(-1, 1)]=mp[ii(-1, 0)]+mp[ii(0, 1)];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    int t; cin >> t;
    while(t--){
        int x, y;
        cin >> x >> y;
        FOR(i, 6) cin >> c[(i+1)%6];
        init();
        ll tmp=min(abs(x), abs(y));
        ll ans= tmp*mp[ii(pow(-1, x<0), pow(-1, y<0))];
        if (abs(x)==tmp){
            if (y<0) ans += abs(y+tmp)*mp[ii(0, -1)];
            else ans += (y-tmp)*mp[ii(0, 1)];
        } else {
            if (x<0) ans += abs(x+tmp)*mp[ii(-1, 0)];
            else ans += (x-tmp)*mp[ii(1, 0)];
        }
        cout << ans << '\n';
    }
}