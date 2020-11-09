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

const int N = 2e6+1;
int t, n, cnt(0), p[N];
bool c[N];

void init(){
    // fill_n(c, sizeof(c)/sizeof(c[0]), true);
    memset(c, true, sizeof(c));
    p[1]=false;
    FOR(i, 2, N){
        if (c[i]){
            p[cnt++]=i;
            for(int j=2; j*i<=N; ++j) c[j*i]=false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    cin >> t;
    map<int, int> mp;
    init();
    while(t--){
        cin >> n;
        if (!mp[n]){
            int x=sqrt(n);
            int l=lower_bound(p, p+cnt+1, x, less_equal<int>())-p;
            int r=lower_bound(p, p+cnt+1, n, less_equal<int>())-p;
            cout << r-l+1 << '\n';
        }
    }
}