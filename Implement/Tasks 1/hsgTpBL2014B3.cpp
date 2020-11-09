// cho ma trận nxn. Sắp xếp ma trận theo thứ tự giảm dần từ trên xuống dưới, từ phải sang trái

#include<bits/stdc++.h>

using namespace std;

const int N = 51;
int n;
int a[N*N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            cin >> a[(i - 1)*n + j]; // (i - 1) * số cột + j
    }
    sort(a + 1, a + n*n + 1, greater<int>());
    for(int i = 1; i <= n; i++){
        for(int j = n; j >= 1; j--)
            cout << a[(i - 1)*n + j] << " ";
        cout << '\n';
    }
}