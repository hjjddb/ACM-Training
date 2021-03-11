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
#define vc vt<char>
#define vi vt<int>
#define vl vt<ll>
#define vvc vt<vc>
#define vvi vt<vi>
#define vvl vt<vl>
#define vii vt<ii>
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
        d8y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

template<class T1, class T2> istream &operator >>(istream &cin, pair<T1, T2> &x){
    cin >> x.fi >> x.se;
    return cin;
}

template<class T1, class T2> ostream &operator <<(ostream &cout, pair<T1, T2> x){
    cout << "(" << x.fi << "," << x.se << ")";
    return cout;
}

template<class T> istream &operator >>(istream &cin, vt<T> &v){
    FOR(v.size()) cin >> v[i];
    return cin;
}

template<class T> ostream &operator <<(ostream &cout, vt<T> &v){
    FOR(v.size()) cout << v[i] << " ";	
    cout << '\n';
    return cout;
}

const int MOD = 1e9+7;
vvl e(int k){
    vvl e(k, vl(k));
    FOR(k) e[i][i]=1;
    return e;
}

vvl operator *(const vvl &x, const vvl &y){
    vvl res(x.size(), vl(y[0].size()));
    FOR(x.size()) FOR(j, y[0].size()) FOR(k, x[0].size())
        res[i][j]=(res[i][j]+x[i][k]*y[k][j])%MOD;
    return res;
}  

vvl powM(const vvl &x, const ll k){
    if (!k) return e(x.size());
    if (k==1) return x;
    vvl half = powM(x, k>>1);
    if (k&1) return half*half*x;
    return half*half;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    int n;
    cin >> n;
    vvl m(2, vl(2));
    m[0][0]=0, m[0][1]=1,
    m[1][0]=1, m[1][1]=2;
    vvl a(2, vl(1, 1));
    if (n<2){
        cout << a[n][0];
        return 0;
    }
    cout << (powM(m, n-1)*a)[1][0]; 

}