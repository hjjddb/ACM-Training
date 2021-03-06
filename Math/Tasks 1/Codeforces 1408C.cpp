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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    int t; cin >> t;
    while(t--){
        int n, l; cin >> n >> l;
        double a[n+2], tL[n+2], tR[n+2], sL(0), sR(0);
        FOR(n) cin >> a[i+1];
        a[0]=0, a[n+1]=l, tL[0]=0, tR[n+1]=0;
        FOR(i, 1, n+2)
            tL[i]=tL[i-1]+double(a[i]-a[i-1])/(++sL);
        FOR(i, n, -1, -1)
            tR[i]=tR[i+1]+double(a[i+1]-a[i])/(++sR);
        FOR(i, 1, n+2){
            if (tL[i]>=tR[i]){
                double sr(n-i+2), sl(i); 
                cout << setprecision(7) << fixed << tL[i]-(tL[i]-tR[i])*sr/(sr+sl) << '\n';
                break;
            }   
        }
    }
}