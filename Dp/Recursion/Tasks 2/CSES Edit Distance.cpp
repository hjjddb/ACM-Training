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

const int N = 5e3+1;
string s, t;
int dp[N][N]; // dp[i][j] = cost to make i elements of s equal to j elements of t (left to right)

int recur(int m, int n){
    if (!m) return n;
    if (!n) return m;
    if (s[m-1] == t[n-1]) return recur(m-1, n-1);
    return 1 + min(recur(m, n-1), // add to s, aka ignore s[m] and t[n-1], recur to s[m-1] and t[n-2], similar to remove t[n-1]
                   min(recur(m-1, n), // remove s[m]
                   recur(m-1, n-1)) // replace s[m-1] by t[n-1], aka ignore s[m-1] and t[n-1]
                   );
}

void solveDP(){
    FOR(s.size()+1) dp[i][0] = i; 
    FOR(t.size()+1) dp[0][i] = i;
    FOR(i, 1, s.size()+1){
        FOR(j, 1, t.size()+1){
            if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    cin >> s >> t;
    solveDP();
    cout << dp[s.size()][t.size()];
}