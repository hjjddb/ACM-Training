#include<bits/stdc++.h>

using namespace std;

const int N = 200 + 2;
int m, n, d, r, h;
int a[N][N];
int ans = INT_MAX;
int arr[N];
int sum;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    cin >> m >> n;
    cin >> d >> r >> h;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            a[i][j] = abs(a[i][j] - h);
        }

    // for(int i = 1; i <= m; i++){
    //     for(int j = 1; j <= n; j++)
    //         cout << a[i][j] << " ";
    //     cout << '\n';
    // }
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            a[i][j] = a[i - 1][j] + a[i][j];
    
    // dat san bay doc
    for(int i = 1; i <= m - d + 1; i++){
        // last row = i + d - 1
        sum = 0;
        for(int j = 1; j <= n; j++)
            arr[j] = a[i + d - 1][j] - a[i - 1][j];
        for(int j = 1; j <= r; j++)
            sum += arr[j];
        ans = min(ans, sum);
        for(int j = r + 1; j <= n; j++){
            sum = sum - arr[j - r] + arr[j];
            ans = min(ans, sum);
        }
    }
    // dat san bay ngang
    for(int i = 1; i <= m - r + 1; i++){
        // last row = i + r - 1
        sum = 0;
        for(int j = 1; j <= n; j++)
            arr[j] = a[i + d - 1][j] - a[i - 1][j];
        for(int j = 1; j <= d; j++)
            sum += arr[j];
        ans = min(ans, sum);
        for(int j = d + 1; j <= n; j++){
            sum = sum - arr[j - d] + arr[j];
            ans = min(ans, sum);
        }
    }
    cout << ans << '\n';
}