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
          N = 1e4+1;;

int n, m, rootA, rootB;
vt<vt<int>> GA, GB;
vt<int> colA[26], colB[26];
int numChildA[N], numChildB[N], dpA[26][N], dpB[26][N];

void dfsA(int u){
    numChildA[u]=1;
    EACH(v, GA[u]){
        dfsA(v);
        numChildA[u]+=numChildA[v];
    }
}

void dfsB(int u){
    numChildB[u]=1;
    EACH(v, GB[u]){
        dfsB(v);
        numChildB[u]+=numChildB[v];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    cin >> n >> m;
    GA = vt<vt<int>>(n), GB = vt<vt<int>>(m);
    FOR(n){
        char c;
        int x;
        cin >> c >> x;
        if (x!=-1) GA[x].pb(i);
        else rootA = i;
        colA[c-'A'].pb(i);
        // } 
    }
    FOR(m){
        char c;
        int x;
        cin >> c >> x;
        if (x!=-1) GB[x].pb(i);
        else rootB = i;
        colB[c-'A'].pb(i);
        
    }
    dfsA(rootA);
    dfsB(rootB);
    int ans(0);
    FOR(26){
        EACH(v, colA[i]) ++dpA[i][numChildA[v]];
        EACH(v, colB[i]) ++dpB[i][numChildB[v]]; 
    }
    FOR(26){
        FOR(j, N){
            if (dpA[i][j]>0&&dpB[i][j]>0) ans = max(ans, j);
        }
    }
    cout << ans;
}   