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

const int N = 1e3+1,
          MOD = 1e9+7;
int n, x, pos;
ll fac[N];

ll powM(ll a, ll k){
    if (!k) return 1;
    if (k==1) return a;
    ll half=powM(a, k/2);
    if (k%2) return (half*half%MOD)*a%MOD;
    return half*half%MOD;
}

ll A(int a, int b){
    return fac[b]*powM(fac[b-a], MOD-2)%MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    cin >> n >> x >> pos;
    set<int> l, r;
    
    fac[0]=1;
    FOR(i, 1, N) fac[i]=(fac[i-1]*i)%MOD;

    int left(0), right(n);
    while (left < right){
        int mid=(left+right)/2;
        if (mid<=pos) left=mid+1, l.insert(mid);
        else right=mid, r.insert(mid);
    }
    if (l.find(pos)!=l.end()) l.erase(pos);
    cout << A(r.size(), n-x)*A(l.size(), x-1)%MOD*fac[n-l.size()-r.size()-1]%MOD;
}