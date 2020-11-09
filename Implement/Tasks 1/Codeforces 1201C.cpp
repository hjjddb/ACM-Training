#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int N = 2e5 + 5;
int n, k;
int a[N];
ll d[N];
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
 
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int m = (1 + n)/2;
    d[n + 1] = LLONG_MAX;
    for(int i = m + 1; i <= n; i++) d[i] = ll(i - m)*ll(a[i] - a[i - 1]) + d[i - 1];
    for(int i = m; i <= n; i++)
        if (d[i] <= k && k < d[i + 1]){
            cout << a[i] + (k - d[i])/(i - m + 1);
            return 0;
        }
    
}