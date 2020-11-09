#include<bits/stdc++.h>
 
using namespace std;
 
typedef pair<int, int> ii;
 
const int N = 2*100005;
int t, n;
int a[N];
int d[N];
ii range[N];
int start;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
 
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            if (a[i] == 1) 
                start = i;
        }
        for(int i = 1; i <= n; i++)
            d[a[i]] = i - start;
        range[1] = make_pair(0, 0);
        cout << 1;
        for(int i = 2; i <= n; i++){
            range[i] = make_pair(min(range[i - 1].first, d[i]), max(range[i - 1].second, d[i]));
            if (range[i].second - range[i].first + 1 <= i)
                cout << 1;
            else 
                cout << 0;
        }
        cout << '\n';
    }
}