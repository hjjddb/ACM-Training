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
          d8y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

struct Point{
    double x, y, z;
} a, b, c;

ar<double, 3> sf(Point A, Point B){
    double res[3];
    res[0] = ;
    res[1] = -(B.z*A.x-B.x*A.z)/(B.)
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    int t;
    cin >> t;
    while(t--){
        int s[3];
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
        FOR(3){
            cin >> s[i];
        }
        a.z = s[0]-1;
        b.z = s[1]-1;
        c.z = s[2]-1;
    }
}