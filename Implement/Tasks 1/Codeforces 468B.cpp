#include<bits/stdc++.h>

using namespace std;

const int N = 1e2;
int n, m,
    a[N][N],
    b[N][N],
    c[N][N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    cin >> n >> m;
    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j)
        a[i][j]=1;
    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) cin >> b[i][j];
    //     neu b[i][j]=1 thi it nhat 1 phan tu trong hang i hoac cot j cua a[][]=1
    // <=> neu b[i][j]=0 thi khong co phan tu nao trong hang i va cot j cua a[][]=1
    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j){
        if (!b[i][j]){ // 0 = false, !0 = true
            for(int k=0; k<m; ++k) a[i][k]=0; // cho tat ca phan tu trong hang i cua a[][] = 0
            for(int k=0; k<n; ++k) a[k][j]=0; // cho tat ca phan tu trong cot j cua a[][] = 0
        }
    }
    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j){
        for(int k=0; k<m; ++k) c[i][j]|=a[i][k];
        for(int k=0; k<n; ++k) c[i][j]|=a[k][j];
    }
    bool ans(1);
    // for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) if (c[i][j]!=b[i][j]){
    //     ans=0;
    //     break;
    // }
    for(int i=0; i<n&&ans; ++i) for(int j=0; j<m&&ans; ++j) 
        ans&=(b[i][j]==c[i][j]);
    if (ans){
        cout << "YES\n";
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j) cout << a[i][j] << " ";
            cout << '\n';
        }
    } else cout << "NO";
}
