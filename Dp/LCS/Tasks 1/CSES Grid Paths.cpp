// https://cses.fi/problemset/task/1638/

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

const int N = 1e3;
const int MOD = 1e9+7;
int n, dp[N][N];
char a[N][N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    cin >> n;
    FOR(n){
        FOR(j, n) cin >> a[i][j];
    }
    memset(dp, 0, sizeof(dp));
    if (a[0][0]!='*') dp[0][0] = 1;
    FOR(n){
        FOR(j, n){
            if (a[i][j]!='*'){
                if (i) dp[i][j] = (dp[i][j]+dp[i-1][j])%MOD;
                if (j) dp[i][j] = (dp[i][j]+dp[i][j-1])%MOD;
            }
        }
    }
    cout << dp[n-1][n-1];
}