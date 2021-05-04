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

const int N(1e5+1);
ll cmin[N], cmax[N];
vi res;
int cnt;

void init(){
    cmin[2] = cmax[2] = 1;
    FOR(i, 3, N){
        int m((i-1)>>1);
        cmin[i] = i-1 + cmin[m] + cmin[i-1-m];
        cmax[i] = i-1 + cmax[i-1];
    }
}
 
void solve(int cost, const int &size, int _l){
    // cout << "! " << size << " " << _l << '\n';
    if (!size) return;
    if (size==1){
        res[_l]=cnt++;
        return;
    }
    if (size==2){
        res[_l]=cnt++;
        res[_l+1]=cnt++;
        return;
    }
    cost -= size-1;
    int l(0), r(size>>1), m((l+r)>>1), id(-1);
    while(l!=m && m!=r && id!=-1){
        if (cmin[m]+cmin[size-1-m]<=cost && cost<=cmax[m]+cmax[size-1-m]) id=m;
        else {
            if (cmin[m]+cmin[size-1-m]>cost) r=m;
            else l=m;
            m=(l+r)>>1;
        }
    }
    if (id==-1) FOR(i, l, r+1) if (cmin[i]+cmin[size-1-i]<=cost && cost<=cmax[i]+cmax[size-1-i]){
        id=i;
        break;
    }
    // cout << "? " << id << '\n';
    int tmp = cost-cmin[id];
    vi left, right;
    if (tmp>cmax[size-1-id]){
        solve(cmin[id]+tmp-cmax[size-1-id], id, _l+1);
        res[_l]=cnt++;
        solve(cmax[size-1-id], size-1-id, _l+id+1);
    } else {
        solve(cmin[id], id, _l+1);
        res[_l]=cnt++;
        solve(tmp, size-1-id, _l+id+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    int test; cin >> test;
    init();
    // FOR(10) cout << i << ": " << cmin[i] << " " << cmax[i] << '\n';
    while(test--){
        int n, k;
        cin >> n >> k;
        if (cmin[n]>k || cmax[n]<k){
            cout << "-1\n";
            continue;
        }
        cnt=0;
        res.resize(n);
        solve(k, n, 0);
        FOR(res.size()) cout << res[i]+1 << " \n"[i==res.size()-1];
    }
}