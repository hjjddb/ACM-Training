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

int n, d;
vt<ii> a;
set<ii> bot, top;
int topsz, botsz;

void fix(){
    while(top.size()>topsz){
        auto it = top.begin();
        bot.insert(*it);
        top.erase(it);
    }
    while(bot.size()>botsz){
        auto it = bot.end();
        --it;
        top.insert(*it);
        bot.erase(it);
    }
    if (d>1){
        auto itt = top.begin(), itb = bot.end();
        --itb;
        while((*itt).fi<(*itb).fi){
            top.insert(*itb);
            bot.insert(*itt);
            top.erase(itt);
            bot.erase(itb);
            itt = top.begin(), itb = bot.end();
            --itb;
        }
    }
}

void add(ii x){
    top.insert(x);
}

void remove(ii x){
    auto it = bot.lower_bound(x);
    if (it==bot.end()) top.erase(x);
    else bot.erase(x);
}

// int trau(){
//     int res(0);
//     FOR(i, d, n){
//         vt<int> v;
//         FOR(j, i-d, i) v.pb(a[j].fi);
//         sort(all(v));
//         int med = (d&1) ? 2*v[d/2] : v[d/2]+v[d/2-1];
//         // EACH(x, v) cout << x << " ";
//         // cout << '\n';
//         // cout << med << " " << a[i].fi << '\n';
//         if (a[i].fi>=med) ++res;
//     }
//     return res;
// }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    cin >> n >> d;
    a = vt<ii>(n);
    botsz=d/2, topsz=d-d/2;
    FOR(n){
        cin >> a[i].fi, a[i].se=i;
    }
    FOR(d) top.insert(a[i]);
    fix();
    int ans(0);
    FOR(i, d, n){
        int med;
        if (d>1) med = (d&1) ? 2*(*top.begin()).fi : ((*top.begin()).fi+((*(--bot.end())).fi));
        else med = (*top.begin()).fi;
        if (a[i].fi>=med) ++ans;
        remove(a[i-d]);
        add(a[i]);
        fix();
    }
    cout << ans;
}