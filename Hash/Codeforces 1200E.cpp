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

const int MOD=1e9+7;
vl p;
struct Hash{
    string str;
    vl val;

    Hash(string s){
        str=s;
        val.pb(0LL);
        FOR(s.size())
            val.pb((val.back()*p[1]+s[i]-'0')%MOD);
    }

    ll get(int l, int r){
        return (val[r]-val[l-1]*p[r-l+1]+1LL*MOD*MOD)%MOD;
    }

    int common(Hash &other){
        FOR(i, min(str.size(), other.str.size()), 0, -1)
            if (get(str.size()-i+1, str.size())==other.get(1, i)) return i;
        return 0;
    }

    void append(string s){
        if (s.empty()) return;
        FOR(s.size()){
            str+=s[i];
            val.pb((val.back()*p[1]+s[i]-'0')%MOD);
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    p.resize(1e6+1);
    p[0]=1, p[1]=256;
    FOR(i, 2, p.size()) p[i]=(p[i-1]*256)%MOD;
    
    int n;
    cin >> n;
    Hash ans = Hash("");
    while(n--){
        string s;
        cin >> s;
        Hash hs(s);
        ans.append(s.substr(ans.common(hs)));
    }
    cout << ans.str;
}