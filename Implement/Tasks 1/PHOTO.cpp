// file:///C:/Users/Long%20Le/OneDrive/Work/Programming/C++/Olp-master/%C4%90%E1%BB%81/%C4%90%E1%BB%81%20luy%E1%BB%87n%209%20d%E1%BB%85.pdf

#include<bits/stdc++.h>

using namespace std;

const int N = 50000 + 4;
int n, d, a, b;
pair<int, int> cost[N];
vector<int> res;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    cin >> n >> d >> a >> b;
    int x, y;
    for(int i = 1; i <= n; i++){
        cin >> x >> y;
        cost[i] = make_pair(x*a + y*b, i);
    }
    sort(cost + 1, cost + n + 1, less<pair<int, int> >());
    int total = 0;
    int i = 1;
    while(total <= d){
        if (total + cost[i].first <= d){
            total += cost[i].first;
            res.push_back(cost[i].second);
            i++;
        }
        else
            break;
    }
    cout << res.size() << '\n';
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
}