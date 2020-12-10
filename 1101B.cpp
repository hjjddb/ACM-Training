#include <bits/stdc++.h>
using namespace std;

string s;
int ans, stop, start, fans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    cin >> s;
    bool check = false;
    for (int i = 0;i<s.length();i++) {
        if (s[i] == '[') {
            for (int j = i + 1;j<s.length();j++) {
                if (s[j] == ':') {
                    start = j;
                    check = true;
                    break;
                }
            }
        }
    }
    
    // if (check == false) {
    //     cout << -1;
    //     return 0;
    // }

    check = false;
    for(int i = s.length();i>=0;i--) {
        if (s[i] == ']') {
            for (int j = i - 1;j>=0;j--) {
                if (s[j] == ':') {
                    stop = j;
                    check = true;
                    break;
                }
            }
        }
    }
    // cout << start << " " << stop;
 
    if (start == stop) {
        cout << "-1";
        return 0;
    }

    // if (check == false) {
    //     cout << "-1";
    //     return 0;
    // }

    for (int i = start;i<=stop;i++) {
        if (s[i] == '|') ans++;
    }

    cout << ans + 4;
    return 0;
}