// https://cses.fi/problemset/task/1755

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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    string s; cin >> s;
    int v[26]; memset(v, 0, sizeof(v));
    FOR(s.size()) v[s[i]-'A']++;
    int flag = s.size()%2+1, c;
    FOR(26) if (v[i]%2) flag -= 1, c=i;
    if (flag>0){
        int cnt = 0;
        FOR(26){
            if (i!=c){
                while(v[i]){
                    s[cnt] = char('A'+i);
                    s[s.size()-cnt-1] = char('A'+i);
                    v[i]-=2;
                    ++cnt;
                }
            } else {
                s[s.size()/2]=char('A'+c);
                --v[c];
                int x=1;
                while(v[c]>0){
                    s[s.size()/2+x] = s[s.size()/2-x] = char('A'+c);
                    x++;
                    v[c]-=2;
                }
            }
        }
        cout << s;
    } else cout << "NO SOLUTION";
}