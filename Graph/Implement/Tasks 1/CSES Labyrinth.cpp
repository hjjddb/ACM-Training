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
          d4i[] = {0, -1, 0, 1},
          d4j[] = {-1, 0, 1, 0};
const char t[] = {'L', 'U', 'R', 'D'};
int n, m, iA, iB, jA, jB, d[N][N];
string s[N];

bool e(int x, int y){
    return 0<=x && x<n && 0<=y && y<m && s[x][y]=='.';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    cin >> n >> m;
    FOR(i, n){
        cin >> s[i];
        FOR(j, m){
            if (s[i][j]=='A') iA=i, jA=j, s[i][j]='.';
            if (s[i][j]=='B') iB=i, jB=j, s[i][j]='.'; 
            d[i][j]=INT_MAX;
        }
    }

    d[iA][jA]=0;
    queue<ar<int, 2>> q;
    q.push({iA, jA});
    while(q.size()){
        ar<int, 2> u = q.front();
        q.pop();

        FOR(k, 4){
            int ni=u[0]+d4i[k], nj=u[1]+d4j[k];
            if (!e(ni, nj)) continue;
            q.push({ni, nj});
            d[ni][nj] = min(d[ni][nj], d[u[0]][u[1]]+1);
            s[ni][nj] = '#';
        }
    }
    if (d[iB][jB]==INT_MAX){
        cout << "NO\n";
        return 0;
    }
    int iT=iB, jT=jB;
    string ans;
    while(iT!=iA || jT!=jA){
        FOR(k, 4){
            int ni=iT+d4i[k], nj=jT+d4j[k];
            if (0<=ni && ni<n && 0<=nj && nj<m){
                if (d[ni][nj]==d[iT][jT]-1){
                    iT=ni;
                    jT=nj;
                    ans+=t[(k+2)%4];
                    break;
                }
            }
        }
    }
    cout << "YES\n";
    reverse(ans.begin(), ans.end());
    cout << d[iB][jB] << '\n' << ans;
}