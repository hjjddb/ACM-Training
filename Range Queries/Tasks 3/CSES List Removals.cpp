#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // freopen("a.inp", "r", stdin);
    // freopen("a.out", "w", stdout);

    int n; cin >> n;
    oset<array<int, 2>> s;
    for(int i=0; i<n; ++i){
        int x; cin >> x;
        s.insert({i, x});
    }
    for(int i=0; i<n; ++i){
        int p; cin >> p;
        auto it = s.find_by_order(p-1);
        cout << (*it)[1] << " ";
        s.erase(it);
    }
}