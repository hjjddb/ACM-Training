#include<bits/stdc++.h>
 
using namespace std;
 
string s[3];
 
int isKoutsu(){
    if (s[0] == s[1] && s[1] == s[2]) return 0;
    if (s[0] == s[1] || s[1] == s[2]) return 1;
    return 2;
}
 
int isShuntsu(){
    if (s[0][1] == s[1][1] && s[1][1] == s[2][1] && s[0][0] - s[1][0] == s[1][0] - s[2][0] && s[0][0] - s[1][0] == -1) return 0;
    if ((s[0][1] == s[1][1] && abs(s[0][0] - s[1][0]) <= 2)
    || (s[1][1] == s[2][1] && abs(s[1][0] - s[2][0]) <= 2)
    || (s[0][1] == s[2][1] && abs(s[0][0] - s[2][0]) <= 2)) {
        return 1;
    }
    return 2;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
 
    for(int i = 0; i < 3; i++) cin >> s[i];
    sort(s, s + 3);
    
    // for(int i = 0; i < 3; i++) cout << s[i] << '\n';
    
 
    // cout << isShuntsu() << '\n';
    cout << min(isKoutsu(), isShuntsu()) << '\n';
}