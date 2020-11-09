#include<bits/stdc++.h>

using namespace std;

const int N = 107;
int n, x;
int sum[N][N];

int main(){
    while(scanf("%d", &n) > 0){
        int ans (0);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++){
                scanf("%d", &sum[i][j]);
                sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            }

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                for(int k = i; k <= n; k++)
                    for(int l = j; l <= n; l++)
                        ans = max(ans, sum[k][l] - sum[i - 1][l] - sum[k][j - 1] + sum[i - 1][j - 1]);
        printf("%d\n", ans);
    }
    return 0;
}
