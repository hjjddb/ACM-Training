#include<bits/stdc++.h>

using namespace std;

int main(){
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int t = 0;
    int n, m;
    while(scanf("%d%d", &n, &m) > 0){
        t++;
        if (t > 1)
        printf("\n");
        int a[n + 1][n + 1], sum[n + 1][n + 1];
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= n; j++)
                sum[i][j] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                scanf("%d", &a[i][j]);
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
            }
        }
        int res[n - m + 2][n - m + 2];
        int total = 0;
        for(int i = 1; i <= n - m + 1; i++){
            for(int j = 1; j <= n - m + 1; j++){
                res[i][j] = sum[m + i - 1][m + j - 1] - sum[i - 1][m + j - 1] - sum[m + i - 1][j - 1] + sum[i - 1][j - 1];
                total += res[i][j];
            }
        }
        for(int i = 1; i <= n - m + 1; i++){
            for(int j = 1; j <= n - m + 1; j++){
                printf("%d\n", res[i][j]);
            }
        }
        printf("%d\n", total);
    }
}
