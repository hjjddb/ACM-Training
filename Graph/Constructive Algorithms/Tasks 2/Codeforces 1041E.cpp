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

const int N = 1e3+1;
int n, a[N];
vt<int> v[N];
vt<ii> e;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    cin >> n;
    FOR(n-1){
        int x, y;
        cin >> x >> y;
        a[x]++;
        a[y]++;
    }
    FOR(i, 1, n+1)
        v[a[i]].pb(i);
    sort(all(v[0]));
    if (a[1]==2 || a[n]!=n-1){
        cout << "NO";
        return 0;
    }
    int x=n-1;
    while(x){
        if (a[x]>1){
            int cnt=a[x]-1;
            vt<int> st;
            while(cnt && v[0].size()){
                int y=v[0].back();
                v[0].pop_back();
                if (x<y){
                    cout << "NO";
                    return 0;
                }
                st.pb(y);
                --cnt;
            }
            if (cnt){
                cout << "NO";
                return 0;
            }
            FOR(st.size()-1) e.pb(ii(st[i], st[i+1]));
            e.pb(ii(st[0], n));
            e.pb(ii(st.back(), x));
        } else if (a[x]==1){
            e.pb(ii(x, n));
        }
        --x;
    }
    cout << "YES\n";
    EACH(x, e) cout << x.fi << " " << x.se << '\n';
}