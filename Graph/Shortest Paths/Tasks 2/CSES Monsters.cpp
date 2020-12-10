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
#define vi vt<int>
#define vl vt<ll>
#define vc vt<char>
#define vii vt<ii>
#define vvi vt<vi>
#define vvl vt<vl>
#define vvc vt<vc>
#define vvii vt<vii>
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
          oo = 1e7;
const char dr[] = {'U', 'L', 'D', 'R'};
int n, m;
vvc s;
ii ans;
vc trace;
vvi d1, d2;

template<class T1, class T2>
ostream &operator <<(ostream &cout, pair<T1, T2> x){
    cout << "(" << x.fi << "," << x.se << ")";
    return cout;
}


template<class T>
void read1(T &x){
    FOR(x.size()) cin >> x[i];
}

template<class T>
void read2(vt<T> &x){
    FOR(x.size()) read1(x[i]);
}

template<class T>
void print1(T &x){
    EACH(xi, x) cout << xi << ' ';
    cout << '\n';
}

template<class T>
void print2(vt<T> &x){
    FOR(x.size()){
        print1(x[i]);
    }
}

bool inside(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<m;
}

bool bound(int x, int y){
    return !(0<x&&x<n-1&&0<y&&y<m-1);
}

void bfs(queue<ii> &q, vvi &d){
    while(q.size()){
        int x=q.front().fi;
        int y=q.front().se;
        q.pop();

        FOR(4){
            int nx(x+d4x[i]), ny(y+d4y[i]);
            if (inside(nx, ny)&&s[nx][ny]=='.'){
                if (d[nx][ny]==oo){
                    d[nx][ny]=min(d[nx][ny], d[x][y]+1);
                    q.push({nx, ny});
                } else d[nx][ny]=min(d[nx][ny], d[x][y]+1);
            } 
        }
    }
}

void dfs(ii u){
    if (u==ans){
        EACH(step, trace) cout << step;
        return;
    }
    FOR(4){
        int x(u.fi), y(u.se), nx(x+d4x[i]), ny(y+d4y[i]);
        if (inside(nx, ny)){
            if (d1[nx][ny]==d1[x][y]+1){
                trace.pb(dr[i]);
                dfs({nx, ny});
                trace.pop_back();
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    cin >> n >> m;
    s = vvc(n, vc(m));
    d1=d2=vvi(n, vi(m, oo));
    queue<ii> q1, q2;
    vii out;
    ii start;

    read2(s);
    FOR(n){
        FOR(j, m){
            if (s[i][j]=='A') q1.push({i, j}), d1[i][j]=0, start={i, j};
            if (s[i][j]=='M') q2.push({i, j}), d2[i][j]=0;
            if ((s[i][j]=='.'||s[i][j]=='A')&&bound(i, j)) out.pb({i, j});
        }
    }
    bfs(q1, d1);
    bfs(q2, d2);
    EACH(oi, out){
        int x(oi.fi), y(oi.se);
        if (d1[x][y]<d2[x][y]){
            cout << "YES\n";
            cout << d1[x][y] << '\n';
            ans = oi;
            dfs(start);
            return 0;
        }
    }
    cout << "NO";
}