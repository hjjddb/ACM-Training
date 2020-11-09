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

const int N = 3e3+1;
int n, nrow, ncol;
ld a, b, llx[2*N], lly[2*N], urx[2*N], ury[2*N], c[N];
set<ld> x, y;
ld row[2*N], col[2*N], ans; // row[i] manage range(row[i-1]+1, row[i])
int node[4*N], lazy[4*N];
map<int, int> mp;

void build(int id, int l, int r){ // node[id] manage range(col[l], col[r]-1)
    if (l==r){
        node[id]=col[l];
        mp[l]=id;
        return;
    }
    int m=(l+r)/2;
    build(2*id, l, m);
    build(2*id+1, m+1, r);
    node[id]=1;
}

void downtree(int id){
    int t=lazy[id];
    node[2*id]=t;
    node[2*id+1]=t;
    lazy[2*id]=t;
    lazy[2*id+1]=t;
    lazy[id]=0;
}

void update(int id, int l, int r, int idf){
    if (r<lly[idf] || ury[idf]<l) return;
    if (lly[idf]<=l && r<=ury[idf]){
        node[id]=c[idf];
        lazy[id]=c[idf];
        return;
    }
    downtree(id);
    int m=(l+r)/2;
    update(2*id, l, m, idf);
    update(2*id+1, m+1, r, idf);
    node[idf]=c[idf];
}

void query(){

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> a >> b >> n;
    FOR(n){
        cin >> llx[i] >> lly[i] >> urx[i] >> ury[i] >> c[i];
        x.insert(llx[i]), x.insert(urx[i]);
        y.insert(lly[i]), y.insert(ury[i]);
    }
    x.insert(0), x.insert(a);
    y.insert(0), y.insert(b);
    int cnt=0;
    for(auto it=x.begin(); it!=x.end(); ++it){
        row[++cnt]=(*it);
    }
    FOR(nrow){
        build(1, 1, ncol);
        FOR(n)
            update(1, 1, n, i);
        query();
    }

}