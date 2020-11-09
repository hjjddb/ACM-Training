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

const int N = 2e5+5;
int n, cnt(1), v[N], p(1);
ar<int, 3>  a[N];
ll dp[N];

bool cmp(ar<int, 3> x, ar<int, 3> y){
    FOR(3) if(x[i]!=y[i]) return x[i]<y[i];
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    cin >> n;
    FOR(n) cin >> a[i][2] >> a[i][0] >> a[i][1];
    sort(a, a+n, cmp);
    map<int, int> mp;
    FOR(n)
        if(v[cnt]<a[i][0]) v[++cnt]=a[i][0], mp[a[i][0]]=cnt;
    FOR(n){
        int tmp1 = lower_bound(v, v+cnt, a[i][2])-v,
            tmp2 = mp[a[i][0]];
        --tmp1;
        while(p<tmp2){
            dp[p+1]=max(dp[p+1], dp[p]);
            ++p;
        }
        dp[tmp2] = max(dp[tmp2], dp[tmp1]+1LL*a[i][1]);
    }
    cout << dp[cnt];
}