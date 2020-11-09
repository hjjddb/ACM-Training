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
const int M = 1e2+1;
const int MOD = 1e9+7;
int n, m, a[N];
vt<int> v;
ll dp[N][M], ans(1);
vt<ll> res;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    cin >> n >> m;
    FOR(i, 1, n+1) cin >> a[i];
    if (!a[1]){
        v.pb(0);
        FOR(i, 1, m+1) dp[0][i] = 1;
    }
    FOR(i, 1, n+1){
        if (a[i]) v.pb(i), dp[i][a[i]] = 1;
    }
    if (!a[n]) v.pb(n+1);
    FOR(v.size()-1){
        // cout << v[i] << " " << v[i+1] << '\n';
        if (v[i]+1<v[i+1]){
            int l = v[i], r = v[i+1];
            if (l){ // tồn tại cận trái
                FOR(j, l+1, r){
                    FOR(k, max(1, a[l]-j+l), min(m, a[l]+j-l)+1){
                        FOR(p, max(1, k-1), min(m, k+1)+1) dp[j][k] = (dp[j][k]+dp[j-1][p]) % MOD;
                        if (r != n+1) 
                            if (abs(k-a[r])>r-j) dp[j][k] = 0;
                    }
                }
            } else { // không có cận trái
                FOR(j, 1, m+1) dp[1][j] = 1;
                FOR(j, 2, r){
                    FOR(k, 1, m+1){
                        FOR(p, max(k-1, 1), min(k+1, m)+1) dp[j][k] = (dp[j][k]+dp[j-1][p]) % MOD;
                        if (r != n+1) // chặn của cận phải
                            if (abs(k-a[r])>r-j) dp[j][k] = 0;
                    }
                }
            }
            ll tmp = 0;
            FOR(k, 1, m+1) tmp = (tmp + dp[r-1][k]) % MOD;
            res.pb(tmp);
        }
        if (abs(a[v[i]]-a[v[i+1]])>v[i+1]-v[i] && v[i] && v[i+1] != n+1) ans=0;
    }
    FOR(res.size()) ans = (ans*res[i]) % MOD;
    cout << ans;
}