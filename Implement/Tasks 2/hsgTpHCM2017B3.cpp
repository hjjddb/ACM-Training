https://drive.google.com/file/d/1Wz2qyL_OgXZHsI-NTPAsvNcci5CC-Wwa/view?fbclid=IwAR2SNOsiX_O4JXj17EFBtvpOG_JGr8OW2XXC8fM8IJ7RMDMbz49q5xF8x-M
#include<bits/stdc++.h>

using namespace std;

const int N = 100 + 2;
int n, m;
int a[N][N];
int flag[N][N];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int res;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    cin >> n >> m;
    for(int i = 0; i <= n + 1; i++) // khởi tạo các đỉnh đều chưa thăm
        for(int j = 0; j <= m + 1; j++){
            a[i][j] = -1;
            flag[i][j] = -1;
        }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if (flag[i][j] < 0) // nếu đỉnh chưa thăm thì gán là "đỉnh đồi tạm thời"
                flag[i][j] = 1;
            for(int k = 0; k < 8; k++){ // kiểm tra có khả năng là đỉnh đồi
                int x = i + dx[k];
                int y = j + dy[k];
                flag[i][j] = flag[i][j] && (a[i][j] >= a[x][y]);
            }
            cout << i << " " << j << " " << flag[i][j] << '\n';
            if (flag[i][j] == 1){ // tất cả các đỉnh lân cận đỉnh đồi đều không phải đỉnh đồi
                for(int k = 0; k < 8; k++){
                    int x = i + dx[k];
                    int y = j + dy[k];
                    flag[x][y] = 0;
                }
            }
            else{ // tất cả những đỉnh lân cận chưa được thăm có độ cao <= độ cao đỉnh này đều không phải đỉnh đồi
                for(int k = 0; k < 8; k++){
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (a[x][y] <= a[i][j] && flag[x][y] < 0)
                        flag[x][y] = 0;
                }
            }
        }
    }
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if (flag[i][j]){
                res++;
                cout << i << " " << j << '\n';
            }
    cout << res << '\n';
}