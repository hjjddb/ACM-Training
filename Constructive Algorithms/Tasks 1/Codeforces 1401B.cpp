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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    int t;
    cin >> t;
    while(t--){
        int x[6];
        FOR(6) cin >> x[i];
        int n = x[0]+x[1]+x[2];
        // cout << min(x[2], x[4])*2 - max(0, x[1] - x[3] - x[4])*2 << '\n';
        int ans = 0;
        if (x[2] >= x[4]){
            ans += 2*x[4], x[2] -= x[4];
            if (x[2] >= x[5]){
                cout << ans << '\n';
            } else {
                x[5] -= x[2];
                if (x[0] >= x[5]) cout << ans << '\n';
                else cout << ans - 2*(x[5] - x[0]) << '\n';
            }
        } else {
            ans += 2*x[2], x[4] -= x[2];
            if (x[0] >= x[5]) cout << ans << '\n';
            else cout << ans - 2*(x[5] - x[0]) << '\n';
            
        }
    }
}