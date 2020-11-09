// https://cses.fi/problemset/task/1092/

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
    
    int n; cin >> n;
    long long s = 1LL * (n+1)*n/2;
    if (s % 2) cout << "NO\n";
    else {
        s/=2;
        cout << "YES\n";
        int x = n, cnt = 1;
        bool c[n+1];
        memset(c, true, sizeof(c));
        while(s>x && s){
            s -= x;
            c[x--] = false;
            ++cnt;
        }    
        if (s) c[s] = false;
        cout << n-cnt << '\n';
        FOR(i, 1, n+1) if(c[i]) cout << i << " ";
        cout << '\n' << cnt << '\n';
        FOR(i, 1, n+1) if(!c[i]) cout << i << " ";
    }
}