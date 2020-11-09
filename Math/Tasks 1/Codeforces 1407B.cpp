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
int n, a[N], b[N], c[N];
bool d[N];
map<ii, int> mp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    FOR(i, 1, N+1){
        FOR(j, 1, N+1){
            mp[ii(i, j)]=__gcd(i, j);
        }
    }
    int t; cin >> t;
    while(t--){
        cin >> n;
        fill_n(a, sizeof(a)/sizeof(a[0]), 0);
        fill_n(c, sizeof(c)/sizeof(c[0]), 0);
        fill_n(d, sizeof(d)/sizeof(d[0]), true);
        int tmp=-1;
        FOR(n){
            cin >> a[i];
            if (c[0]<a[i]) b[0]=a[i], c[0]=a[i], tmp=i;
        }
        d[tmp]=false;
        FOR(i, 1, n){
            tmp=-1;
            FOR(j, n){
                if (d[j] && mp[ii(c[i-1], a[j])]>c[i]){
                    c[i]=mp[ii(c[i-1], a[j])];
                    tmp=j;
                }
            }
            b[i]=a[tmp];
            d[tmp]=false;
        }
        FOR(n) cout << b[i] << " ";
        cout << '\n';
    }
}