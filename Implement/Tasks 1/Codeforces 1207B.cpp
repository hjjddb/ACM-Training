#include<bits/stdc++.h>
 
using namespace std;
 
const int N = 51; 
int n, m;
int a[N][N], b[N][N];
int dx[] = {0, 0, 1, 1};
int dy[] = {0, 1, 1, 0};
int ansX[N*N], ansY[N*N];
int cnt;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> a[i][j];
 
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            bool flag = true;
            for(int k = 0; k < 4; k++) 
                flag = flag && (a[i + dx[k]][j + dy[k]]);
            if (flag){
                ansX[++cnt] = i;
                ansY[cnt] = j;
                for(int k = 0; k < 4; k++) 
                    b[i + dx[k]][j + dy[k]] = 1;
            }
        }
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            if (a[i][j] != b[i][j]){
                cout << -1;
                return 0;
            }
        }
    cout << cnt << '\n';
    for(int i = 1; i <= cnt; i++)
        cout << ansX[i] << " " << ansY[i] << '\n';
    return 0;
}