#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> c(n);
    for(int i=0; i<n; ++i) cin >> c[i];
    sort(c.begin(), c.end());
    long long ans(0), x(1);
    for(int i=n-1; i>=0; --i) ans += x*c[i], x*=2;
    cout << ans; 
}
