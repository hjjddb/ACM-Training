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

const int N = 1e4+1;
int t, n, s, a[N];
vt<pair<ii, int>> ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    cin >> t;
    while(t--){
        cin >> n;
        memset(a, 0, sizeof(a));
        s=0;
        ans.clear();
        set<ii> d;
        FOR(i, 1, n+1){
            cin >> a[i];
            s+=a[i];
            if (i!=1) d.insert(ii((i-a[i]%(i))%i, i));
        }
        if (s%n) cout << "-1\n";
        else{
            s/=n;
            while(d.size()){
                ii u=(*d.begin());
                d.erase(u);
                if (u.fi) ans.pb(make_pair(ii(1, u.se), u.fi));
                // cout << 1 << " " << u.se << " " << u.fi << "\n";
                
                a[1]-=u.fi;
                a[u.se]+=u.fi;

                ans.pb(make_pair(ii(u.se, 1), a[u.se]/u.se));
                // cout << u.se << " 1 " << a[u.se]/u.se << " \n";

                a[1]+=a[u.se];
                a[u.se]=0;

                // FOR(n) cout << a[i+1] << " ";
                // cout << '\n';
            }
            FOR(i, n, 0, -1){
                if(a[i]<s){
                    int tmp=s-a[i];
                    ans.pb(make_pair(ii(1, i), tmp));

                    // cout << 1 << " " << i << " " << tmp << '\n';
                    
                    a[i]+=tmp;
                    a[1]-=tmp;

                    // FOR(n) cout << a[i+1] << " ";
                    // cout << '\n';
                }
            }
            cout << ans.size() << '\n';
            EACH(x, ans) cout << x.fi.fi << " " << x.fi.se << " " << x.se << '\n';
        }
    }
}