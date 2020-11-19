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

const int MOD=1e9+7;

struct Mat{
    int nrow, ncol;
    ll c[3][3];

    Mat(int nrow, int ncol){
        this->nrow=nrow;
        this->ncol=ncol;
        FOR(i, 1, 3){
            FOR(j, 1, 3) this->c[i][j]=0;
        }
    }

    Mat(int nrow, int ncol, ll d){
        this->nrow=nrow;
        this->ncol=ncol;
        FOR(i, 1, nrow+1)
            this->c[i][i]=d;
    }

    void show(){
        FOR(i, 1, nrow+1){
            FOR(j, 1, ncol+1) cout << c[i][j] << " ";
            cout << '\n';
        }
    }
};

Mat operator * (const Mat& x, Mat y){
    Mat res = Mat(x.nrow, y.ncol);
    FOR(i, 1, x.nrow+1)
        FOR(j, 1, y.ncol+1)
            FOR(k, 1, x.ncol+1)
                res.c[i][j]=(res.c[i][j]+(x.c[i][k]%MOD*y.c[k][j]%MOD)%MOD)%MOD;
    return res;
}

Mat powM(const Mat& x, ll k){
    if (k==0) return Mat(x.nrow, x.ncol, 1);
    if (k==1) return x;
    Mat half=powM(x, k/2);
    if (k%2) return half*half*x;
    return half*half;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    Mat x=Mat(2, 2);
    x.c[1][2]=1;
    x.c[2][1]=1;
    x.c[2][2]=1;
    ll n; cin >> n;
    if (!n){
        cout << 0;
        return 0;
    }
    Mat y=powM(x, n-1);
    Mat res=Mat(2, 1);
    res.c[1][1]=0;
    res.c[2][1]=1;
    res=y*res;
    cout << res.c[2][1];
}