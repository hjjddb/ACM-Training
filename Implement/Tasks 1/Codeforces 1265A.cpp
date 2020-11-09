#include<bits/stdc++.h>

using namespace std;

int t;
string s;
char p[] = {'a', 'b', 'c'};

int main(){
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    cin >> t;
    while(t--){
        cin >> s;
        int n = s.size();
        s = "x" + s + "x";
        bool flag = true;
        for(int i = 1; i <= n; i++){
            if (s[i] != '?')
                if (s[i] == s[i - 1] || s[i] == s[i + 1]){
                    flag = false;
                    break;
                }
                else{

                }
            else{
                for(int j = 0; j < 3; j++)
                    if (s[i - 1] != p[j] && p[j] != s[i + 1]){
                        s[i] = p[j];
                        break;
                    }
            }
        }
        if (flag){
            for(int i = 1; i <= n; i++)
                cout << s[i];
            cout << '\n';
        }
        else 
            cout << "-1\n";
    }
}