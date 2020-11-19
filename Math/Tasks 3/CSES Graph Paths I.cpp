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
          d8y[] = {-1, 0, 1, -1, 1, -1, 0, 1}, 
          MOD = 1e9+7;

struct Mat {
    int nrow, ncol;
    vt<vt<ll>> c;

    Mat(int nrow, int ncol){
        this->nrow = nrow;
        this->ncol = ncol;
        this->c = vt<vt<ll>>(nrow+1, vt<ll>(ncol+1, 0));
    }

    void show(){
        FOR(i, 1, nrow+1){
            FOR(j, 1, ncol+1) cout << this->c[i][j] << " ";
            cout << '\n';
        }
    }
};

Mat E(int nrow, int ncol){
    Mat res = Mat(nrow, ncol);
    FOR(i, 1, min(nrow, ncol)) res.c[i][i]=1;
    return res;
}

Mat operator * (Mat x, Mat y){
    Mat res = Mat(x.nrow, y.ncol);
    FOR(i, 1, res.nrow+1)
        FOR(j, 1, res.ncol+1)
            FOR(k, 1, x.ncol+1) res.c[i][j] = (res.c[i][j]+x.c[i][k]*y.c[k][j])%MOD;
    return res;
}

Mat powM(Mat x, int y){
    if (!y) return E(x.nrow, x.ncol);
    if (y==1) return x;
    Mat half = powM(x, y/2);
    if (y&1) return half*half*x;
    return half*half;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;
    Mat x = Mat(n, n);
    while(m--){
        int u, v;
        cin >> u >> v;
        ++x.c[u][v];
    }
    Mat powX = powM(x, k);
    cout << powX.c[1][n];
}