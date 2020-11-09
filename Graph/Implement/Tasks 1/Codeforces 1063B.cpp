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
#define iiii pair<ii, ii>
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

const int d4i[] = {-1, 0, 1, 0},
          d4j[] = {0, -1, 0, 1},
          N = 2e3+1;
const ii dij[] = {{0, 0}, {1, 0}, {0, 0}, {0, 1}},
         oo = {1e9+1, 1e9+1};
int n, m, r, c, x, y, ans;
ii d[N][N];
string s[N];

bool e(ii u){
    return 0<=u.fi && u.fi<n && 0<=u.se && u.se<m && s[u.fi][u.se]=='.';
}

bool cmp(ii x, ii y){
    return x.fi<=y.fi && x.se<=y.se;
}

ii operator + (const ii &x, ii y){
    return {x.fi+y.fi, x.se+y.se};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    cin >> n >> m >> r >> c >> x >> y;
    FOR(n){
        cin >> s[i];
        FOR(j, s[i].size()) d[i][j] = oo;
    }

    d[r-1][c-1] = {0, 0};
    priority_queue<iiii, vt<iiii>, greater<iiii>> pq;
    pq.push({{0, 0}, {r-1, c-1}});
    int cnt = 0;
    while(pq.size()){
        ii u = pq.top().se;
        ii du = pq.top().fi;
        pq.pop();
        // cout << u.fi << " " << u.se << '\n';
        
        if (du != d[u.fi][u.se]) continue;
        FOR(4){
            ii v = {u.fi+d4i[i], u.se+d4j[i]};
            if (e(v)){
                d[v.fi][v.se] = min(d[v.fi][v.se], du+dij[i]);
                pq.push({d[v.fi][v.se], v});
                s[v.fi][v.se] = '*';
            }
        }
        cnt++;
    }

    FOR(i, n)
        FOR(j, m)
            if (cmp(d[i][j], {x, y})) ans++;
    cout << ans;
}