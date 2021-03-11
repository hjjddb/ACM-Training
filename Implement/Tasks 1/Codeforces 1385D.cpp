#include<bits/stdc++.h>

using namespace std;

int calc(string s, char c){
    int n=s.size();
    if (n==1) return s[0]!=c;
    int cost[] = {0, 0};
    // cost[0] -> bien nua dau cua s thanh toan ki tu c
    // cost[1] -> ...
    for(int i=0; i<n/2; ++i) cost[0]+=s[i]!=c; // if (s[i]!=c) ++cost[0];
    for(int i=n/2; i<n; ++i) cost[1]+=s[i]!=c;
    return min(cost[0]+calc(s.substr(n/2, n/2), c+1), 
               calc(s.substr(0, n/2), c+1)+cost[1]); 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        cout << calc(s, 'a') << '\n';
    }
}