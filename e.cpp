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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    int n; cin >> n;
    vt<int> v;
    FOR(n){
        int x;
        cin >> x;
        v.pb(x);
    }
    vt<vt<int>> c(32);
    EACH(x, v){
        // FOR(k, 31, -1, -1){
        //     if (x&(1<<k)){
        //         c[k+1].pb(x);
        //         break;
        //     }       
        // }
        c[32-__builtin_clz(x)].pb(x);
    }
    FOR(k, 0, 32){
    	if(c[k].size()){
    	}
    }
    int ans(INT_MAX);
    vt<int> d(32);
    FOR(i, 32){
        if (i) d[i]=d[i-1]+c[i].size();
        if (c[i].size()){
    		cout << i << ": ";
    		EACH(x, c[i]) cout << x << " ";
    		cout << '\n';
            vt<int> subc[i];
            EACH(x, c[i]) {
                bool flag=false;
                FOR(k, i-2, -1, -1){
                    if (x&(1<<k)){
                        subc[k+1].pb(x);
                        flag=true;
                        break;
                    }
                    // if (!flag) subc[0].pb(x);
                }
            }
            FOR(k, 0, i){
                if (subc[k].size()){
                    cout << "   " << k << ": ";
                    EACH(x, subc[k]) cout << x << " ";
                    cout << '\n';
                }
            }
            int tmp(0), maxC(0);
            int l(0);
            FOR(j, i+1, 32) if (c[j].size()) tmp+=c[j].size()-1;
            FOR(j, i) l+=c[j].size();
            tmp+=l-(l>0);
            FOR(k, i){
                if (subc[k].size()){
                    // EACH(x, subc[k]) cout << x << " ";
                    // cout << '\n';
                    // cout << "k: " << k << "| ";
                    int tmp1(0), left(0), right(0);
                    FOR(j, k) left+=subc[j].size();
                    tmp1+=left-(left>0);
                    FOR(j, k+1, i) right+=subc[j].size();
                    tmp1+=right-(right>0);
                    // cout << tmp1 << '\n';
                    tmp+=tmp1;
                }
            }
            // cout << '\n';
            // cout << tmp << '\n';
            ans = min(ans, tmp);
        }
    }
    cout << ans;
}