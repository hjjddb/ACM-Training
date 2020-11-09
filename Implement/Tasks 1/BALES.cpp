// file:///C:/Users/Long%20Le/OneDrive/Work/Programming/C++/Olp-master/%C4%90%E1%BB%81/%C4%90%E1%BB%81%20luy%E1%BB%87n%209%20d%E1%BB%85.pdf

#include<bits/stdc++.h>

using namespace std;

const int N = 10000 + 4;
int n;
int a[N];
int sum, res;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    sum /= n;
    for(int i = 1; i <= n; i++)
        res += max(0, sum - a[i]);
    cout << res << '\n';
}