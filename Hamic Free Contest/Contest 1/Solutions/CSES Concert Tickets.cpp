#include<bits/stdc++.h>
 
using namespace std;
 
#define ar array
 
const int N = 200005;
int n, m;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
 
    cin >> n >> m;
    set<ar<int, 2>> s;
    for(int i = 1; i <= n; i++){
        int h;
        cin >> h;
        s.insert(ar<int, 2>({h, i}));
    }
    for(int i = 1; i <= m; i++){
        int t;
        cin >> t;
        auto it = s.lower_bound(ar<int, 2>({t + 1, 0}));
        if (it == s.begin())
            cout << "-1\n";
        else{
            --it;
            cout << (*it)[0] << '\n';
            s.erase(it);
        }
    }
}