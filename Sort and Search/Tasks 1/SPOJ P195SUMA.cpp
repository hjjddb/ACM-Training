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
		  N = 2e5+5;
int n, k, a[N];

int bs(){
	int l(1), r(1e9), m((l+r)/2);
	while(l!=m && m!=r){
		int v = upper_bound(a+1, a+n+1, m)-a-1;
		if (v<k) l=m+1;
		else r=m;
		m=(l+r)/2;
	}
	for(int i=l; i<=r; ++i) if (upper_bound(a+1, a+n+1, i)-a-1==k) return i;
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("test.inp", "r", stdin);
	// freopen("test.out", "w", stdout);

	cin >> n >> k;
	FOR(n) cin >> a[i+1];
	sort(a+1, a+n+1);
	cout << bs();
}