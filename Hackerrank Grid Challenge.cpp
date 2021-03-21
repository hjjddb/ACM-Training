#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<string> s(n);
        for(int i=0; i<n; ++i) cin >> s[i];
        for(int i=0; i<n; ++i) sort(s[i].begin(), s[i].end());
        bool ans(1);
        for(int j=0; j<n; ++j) for(int i=0; i<n-1; ++i) ans=min(ans, s[i][j]<=s[i+1][j]);
        cout << (ans? "YES" : "NO") << '\n'; 
    }
}
