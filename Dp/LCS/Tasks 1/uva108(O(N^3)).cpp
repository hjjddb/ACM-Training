#include<bits/stdc++.h>

using namespace std;

const int N = 107;
int sum[N][N];
int d[N];
int n;

int main(){
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    while(scanf("%d", &n) > 0){
        // input
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                sum[i][j] = 0;
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                scanf("%d", &sum[i][j]);
                sum[i][j] += sum[i - 1][j];
            }
        }
        // dp wiht Kadane
        int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i; j <= n; j++){
                memset(d, 0, sizeof d);
                for(int k = 1; k <= n; k++){
                    d[k] = sum[j][k] - sum[i - 1][k];
                }
                // Kadane algorithm
                int cur (0), maxCur (0);
                for(int k = 1; k <= n; k++){
                    cur += d[k];
                    maxCur = max(maxCur, cur);
                    cur = max(cur, 0);
                }
                ans = max(ans, maxCur);
            }
        } 
        printf("%d\n", ans);
    }
}
