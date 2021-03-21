#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(), cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    int ans(0);
    vector<int> a;
    for(int i=0; i<n; ++i){
        int x, y;
        cin >> x >> y;
        if (y) a.push_back(x);
        else ans+=x;
    }
    sort(a.begin(), a.end(), greater<int>());
    for(int i=0; i<min(k, (int)a.size()); ++i) ans+=a[i];
    for(int i=k; i<a.size(); ++i) ans-=a[i];
    cout << ans;
}
