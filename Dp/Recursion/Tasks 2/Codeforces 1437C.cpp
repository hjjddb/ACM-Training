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

const int N = 2e2+1,
          oo = 1e6;
int q, n, x, c, dp[N][2*N], mp[N];
vt<int> a;

void init(){
    a.clear();
    c=1;
    FOR(i, 1, N){
        mp[i]=0;
        FOR(j, 2*N) dp[i][j]=oo;
    }
    FOR(2*N) dp[0][i]=0;
}

int cost(int start, int num, int val){
    if (start>val) return (2*start+num-1)*num/2-num*val;
    if (start+num<=val) return num*val - (2*start+num-1)*num/2;
    int l(val-start+1), r(num-l);
    return l*val-(val+start)*l/2 + (2*val+r+1)*r/2-r*val;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    cin >> q;
    while(q--){
        init();
        cin >> n;
        FOR(n){
            cin >> x;
            ++mp[x];
        }
        a.pb(0);
        FOR(i, 1, N) if (mp[i]) a.pb(i);
        FOR(i, 1, a.size()){
            int num(mp[a[i]]);
            FOR(j, c+num-1, 2*N+1){
                int start(j-num+1), val(a[i]);
                dp[i][j]=min((dp[i][j], dp[i-1][start-1]+cost(start, num, val)), dp[i][j-1]);
            }
            c+=num;
        }
        // FOR(i, 1, a.size()){
        //     FOR(j, 1, c+N)
        //         cout << dp[i][j] << " ";
        //     cout << '\n';
        // }
        int ans=INT_MAX;
        FOR(j, 1, 2*N+1) ans = min(ans, dp[a.size()-1][j]);
        cout << ans << '\n';
        // cout << dp[a.size()-1][2*N] << '\n';
    }
}