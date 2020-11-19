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
          MOD = 1e9+7;

#define Mat vt<vt<ll>>
Mat E;

Mat operator * (const Mat &x, const Mat &y){
    Mat res(x.size(), vt<ll>(y[0].size()));
    FOR(res.size())
        FOR(j, res[0].size())
            FOR(k, x[0].size())
                res[i][j]=(res[i][j]+x[i][k]*y[k][j])%MOD;
    return res;
}

Mat powM(Mat x, ll k){
    if (!k) return E;
    if (k==1) return x;
    Mat half = powM(x, k/2);
    if (k&1) return half*half*x;
    return half*half;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    ll n;
    cin >> n;
    
    E = Mat(6, vt<ll>(6));
    FOR(6) E[i][i]=1;
    vt<ll> dp(13);
    dp[0]=1;
    FOR(i, 1, 13)
        FOR(j, 1, min(6, i)+1)
            dp[i]=(dp[i]+dp[i-j])%MOD;
    if (n<6){
        cout << dp[n];
        return 0;
    }
    Mat f = Mat(6, vt<ll>(6));
    FOR(i, 5) f[i][i+1]=1;
    FOR(j, 6) f[5][j]=1;
    Mat pf = powM(f, n-6);
    Mat x = Mat(6, vt<ll>(1));
    FOR(6) x[i][0] = dp[i+1];
    Mat res = pf*x;
    cout << (pf*x)[5][0];
}