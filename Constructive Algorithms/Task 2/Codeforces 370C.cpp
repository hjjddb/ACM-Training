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

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vi a(n);
    vvi c;
    FOR(m+1) c.pb({0, i});
    FOR(n) cin >> a[i], ++c[a[i]][0];
    sort(all(c), greater<vi>());
    if (n==1){
        cout << "0\n" << a[0] << " " << a[0];
        return 0;
    }
    a.clear();
    FOR(m+1) FOR(j, c[i][0]) a.pb(c[i][1]);
    int ans(0);
    int k(0);
    while(a[k]==a[k+1]){
        ++k;
        if (k==n-1) break;
    }
    vvi res;
    FOR(n){
        res.pb({a[i], a[(i+k+1)%n]});
        ans += a[i]!=a[(i+k+1)%n];
    }
    cout << ans << '\n' << res;
}