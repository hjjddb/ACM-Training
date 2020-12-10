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

const int oo = 1e8;
int n, d8x[8], d8y[8];
vt<vt<int>> d;

bool inside(int r, int c){
	return 0<=r&&r<n&&0<=c&&c<n;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("test.inp", "r", stdin);
	// freopen("test.out", "w", stdout);

	cin >> n;
	FOR(a, 1, n){
		FOR(b, 1, n){
			d = vt<vt<int>>(n, vt<int>(n, oo));
			int dx[] = {-a, -a, a, a, -b, -b, b, b},
				dy[] = {-b, b, -b, b, -a, a, -a, a};
			// FOR(8) d8x[i] = dx[i], d8y[i] = dy[i];
			// FOR(n) FOR(j, n) d[i][j] = oo;
			d[0][0] = 0;
			queue<ii> q;
			q.push({0, 0});

			while(q.size()){
				int r(q.front().fi), c(q.front().se);
				q.pop();

				FOR(k, 8){
					int nr(r+dx[k]), nc(c+dy[k]);
					if (inside(nr, nc)){
						if (d[nr][nc]==oo){
							d[nr][nc] = d[r][c]+1;
							q.push({nr, nc});
						} else d[nr][nc] = min(d[nr][nc], d[r][c]+1);
					}
				}
			}
			// FOR(n){
			// 	FOR(j, n){
			if (d[n-1][n-1]==oo) d[n-1][n-1]=-1;
			cout << d[n-1][n-1] << " ";
				// }
			// }
		}
		cout << '\n';
	}
}