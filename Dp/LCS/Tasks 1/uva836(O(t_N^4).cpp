#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int a[n + 1][n + 1], sum[n + 1][n + 1];
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                sum[i][j] = 0;
        for(int j = 0; j < n; j++)
            a[1][j + 1] = s[j] - '0';
        for(int i = 2; i <= n; i++){
            cin >> s;
            for(int j = 0; j < n; j++)
                a[i][j + 1] = s[j] - '0';
        }
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];

        int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                for(int k = 1; k <= i; k++){
                    for(int l = 1; l <= j; l++){
                        int s1 = (i - k + 1)*(j - l + 1);
                        int s2 = sum[i][j] - sum[k - 1][j] - sum[i][l - 1] + sum[k - 1][l - 1];
                        if (s1 == s2) 
                            ans = max(ans, s1);
                    }
                }
            }
        }
        cout << ans << "\n";
        if (t)
            cout << '\n';
    }
}
