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
		  d6x[] = {-1, 0, 1, 0, 0, 0},
		  d6y[] = {0, -1, 0, 1, 0, 0},
		  d6z[] = {0, 0, 0, 0, -1, 1},
		  N = 30, 
		  oo = 1e5;
int l, r, c;
int ex, ey, ez;

bool valid(int x, int y, int z){
	return 0<=x&&x<l&&0<=y&&y<r&&0<=z&&z<c;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("test.inp", "r", stdin);
	// freopen("test.out", "w", stdout);
	
	while(cin >> l >> r >> c){
		// cout << l << r << c << '\n';
		if (l||r||c){
			queue<ar<int, 3>> q;
        	vt<vt<vt<int>>> d(l);
			EACH(i, d) 
				i.resize(r, vector<int>(c, oo));
			FOR(l){
				FOR(j, r){
					FOR(k, c){
						char x; cin >> x;
						if (x=='#') d[i][j][k] = -1;
						if (x=='S') d[i][j][k] = 0, q.push({i, j, k});
						if (x=='E') ex=i, ey=j, ez=k;
					}
				}
			}
			while(q.size()){
				ar<int, 3> u = q.front();
				q.pop();
				int x(u[0]), y(u[1]), z(u[2]);
				FOR(6){
					int nx(x+d6x[i]), ny(y+d6y[i]), nz(z+d6z[i]);
					if (valid(nx, ny, nz)){
						if (d[nx][ny][nz]==oo){
							d[nx][ny][nz] = d[x][y][z]+1;
							q.push({nx, ny, nz});
						}
					}
				}
			}
			if (d[ex][ey][ez]!=oo) cout << "Escaped in " << d[ex][ey][ez] << " minute(s).\n";
			else 
				cout << "Trapped!";
		} else return 0;

	}
}
