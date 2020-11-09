#include<bits/stdc++.h>

using namespace std;

const int N = 300000 + 5;
int n;
int a[N];
vector<int> pos, neg;
int ans = INT_MIN;

int main(){
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        ans = max(ans, a[i]);
        printf("%d ", ans);
    }
    ans = INT_MAX;
    sort(a + 1, a + n + 1, less<int>());
    for(int i = 1; i <= n; i++){
        if (a[i] <= 0)
            neg.push_back(a[i]);
        else 
            pos.push_back(a[i]);
    }
    if (!neg.empty() && !pos.empty()){
        for(int i = 0; i < neg.size(); i++){
            int x = abs(neg[i]);
            vector<int>::iterator it = lower_bound(pos.begin(), pos.end(), x); // trả về con trỏ lưu vị trí của phần tử đầu tiên >= x ở trong đoạn [begin, end) của pos
            // nếu quên hoặc lười thì dùng auto như dưới
            // auto it = lower_bound(pos.begin(), pos.end(), x);
            if (it == pos.end()){
                ans = min(ans, abs(x - pos[it - pos.begin() - 1]));
            }
            else{
                if (it == pos.begin())
                    ans = min(ans, abs(x - pos[it - pos.begin()]));
                else 
                    ans = min(ans, min(pos[it - pos.begin()], pos[it - pos.begin() - 1]));
            }
        }
    }
    else{
        if (neg.empty()) 
            ans = abs(neg[neg.size() - 1] + neg[neg.size() - 2]);
        else 
            ans = pos[0] + pos[1];
    }
    printf("\n%d\n", ans);
    ans = 0;
    int sum = 0;
    for(int i = 0; i < neg.size(); i++)
        sum += neg[i];
    ans = max(ans, abs(sum));
    sum = 0;
    for(int i = 0; i < pos.size(); i++)
        sum += pos[i];
    ans = max(ans, sum);
    printf("%d\n", ans);
}