// file:///C:/Users/Long%20Le/OneDrive/Work/Programming/C++/Olp-master/%C4%90%E1%BB%81/%C4%90%E1%BB%81%20luy%E1%BB%87n%209%20d%E1%BB%85.pdf

#include<bits/stdc++.h>

using namespace std;

string s;
vector<int> bg, ed;
int res;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    cin >> s;
    for(int i = 0; i < s.size() - 1; i++){
        if (s[i] == '(' && s[i + 1] == s[i])
            bg.push_back(i);
        if (s[i] == ')' && s[i + 1] == s[i])
            ed.push_back(i);
    }
    for(int i = 0; i < bg.size(); i++){
        auto it = lower_bound(ed.begin(), ed.end(), bg[i]);
        // cout << bg[i] << " " << it - ed.begin() << '\n';
        res += max(ed.end() - it, 0);
    }
    cout << res << '\n';
}