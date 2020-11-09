#include<bits/stdc++.h>

using namespace std;

const int N = 1001;
int m, n, t;
int a[N][N];
int v[N][N][4];
int res;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    cin >> m >> n >> t;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++){
            if (a[i][j]){
                if (a[i][j] == a[i - 1][j])
                    v[i][j][0] = v[i - 1][j][0] + 1;  
                else
                    v[i][j][0] = 1;
                if (a[i][j] == a[i][j - 1])
                    v[i][j][1] = v[i][j - 1][1] + 1;  
                else
                    v[i][j][1] = 1;
            }
        }
    for(int i = m; i >= 1; i--)
        for(int j = n; j >= 1; j--){
            if (a[i][j]){
                if (a[i][j] == a[i + 1][j])
                    v[i][j][2] = v[i + 1][j][2] + 1;  
                else
                    v[i][j][2] = 1;
                if (a[i][j] == a[i][j + 1])
                    v[i][j][3] = v[i][j + 1][3] + 1;  
                else
                    v[i][j][3] = 1;
            }
        }

    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++){
            // cout << "check " << i << " " << j << " | " << v[i][j][0] + v[i][j][2] - 1 << " " << v[i][j][1] + v[i][j][3] - 1 << '\n';
            if (a[i][j] && v[i][j][0] + v[i][j][2] - 1 < t && v[i][j][1] + v[i][j][3] - 1 < t)
                res++;
        }
    cout << res << '\n';
}