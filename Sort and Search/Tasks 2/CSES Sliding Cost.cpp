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

const int N = 2e5;
int n, k, a[N];
ll d[N];
set<ii> bot, top;
ll sBot, sTop;

void fix(){
    while(bot.size() > (int)ceil(k/2)){
        auto it = bot.end();
        --it;
        top.insert(*it);
        bot.erase(it);
        sTop += (*it).fi;
        sBot -= (*it).fi;
    }
    while(top.size() > k/2){
        auto it = top.begin();
        bot.insert(*it);
        top.erase(it);
        sBot += (*it).fi;
        sTop -= (*it).fi;
    }
}

void add(ii x){
    if (!bot.size()){
        bot.insert(x);
        sBot += x.fi;
        return;
    }
    if (*--bot.end() > x) bot.insert(x), sBot+=x.fi;
    else top.insert(x), sTop+=x.fi;
    fix();
}

void rm(ii x){
    if (bot.find(x) != bot.end()) bot.erase(x), sBot-=x.fi;
    else top.erase(x), sTop-=x.fi;
    fix();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    cin >> n >> k;
    FOR(n) cin >> a[i];
    if (k==2) FOR(n-1) cout << abs(a[i+1] - a[i]) << " ";
    else{
        FOR(k-1) add({a[i], i});
        FOR(i, k-1, n){
            add({a[i], i});
            cout << sTop - sBot + (k%2)*(*--bot.end()).fi << " ";
            rm({a[i-k+1], i-k+1});
        }
    }
}