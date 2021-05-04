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
#define vb vt<bool>
#define vc vt<char>
#define vi vt<int>
#define vl vt<ll>
#define vvb vt<vb>
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

ostream &operator <<(ostream &cout, vc &v){
    FOR(v.size()) cout << v[i] << " \n"[i==v.size()-1];
    return cout;
}

ostream &operator <<(ostream &cout, vi &v){
    FOR(v.size()) cout << v[i] << " \n"[i==v.size()-1];
    return cout;
}

ostream &operator <<(ostream &cout, vl &v){
    FOR(v.size()) cout << v[i] << " \n"[i==v.size()-1];
    return cout;
}

template<class T> ostream &operator <<(ostream &cout, const vt<vt<T>> &v){
    FOR(v.size()) FOR(j, v[i].size()) cout << v[i][j] << " \n"[j==v[i].size()-1];
    return cout;
}

bool isPrime(int x){
    if (x<2) return false;
    for(int i=2; i*i<=x; ++i) if (!(x%i)) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    const int MOD(1e9+7);
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        map<int, int> m;
        FOR(n){
            int x;
            cin >> x;
            ++m[x];
        }
        vvl c(m.size()+1, vl(8192));
        c[0][0] = 1;
        int cnt(0);
        EACH(i, m){
            ++cnt;
            FOR(j, 8192){
                c[cnt][i.fi^j] += 1LL*(i.se/2+i.se%2)*c[cnt-1][j];
                c[cnt][i.fi^j] %= MOD;
                c[cnt][j] += 1LL*(i.se/2+1)*c[cnt-1][j]%MOD;
                c[cnt][j] %= MOD;
            }
        }
        ll ans(0);
        FOR(8192) ans = (ans+isPrime(i)*c[m.size()][i])%MOD;
        cout << ans << '\n';
    }
}