// https://cses.fi/problemset/task/1624/

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

bool a[8][8], c[8], d1[15], d2[15];
int ans;

void backtrack(int id){
    FOR(8){
        if (a[id][i] && c[i] && d1[i-id+7] && d2[i+id]){
            c[i] = d1[i-id+7] = d2[i+id] = false;
            if (id == 7) ++ans;
            else {
                backtrack(id+1);
            }
            c[i] = d1[i-id+7] = d2[i+id] = true;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    memset(a, true, sizeof(a));
    memset(c, true, sizeof(c));
    memset(d1, true, sizeof(d1));
    memset(d2, true, sizeof(d2));
    string s;
    FOR(8){
        cin >> s;
        FOR(j, 8) a[i][j] = (s[j]=='.');
    }
    backtrack(0);
    cout << ans << '\n';
}