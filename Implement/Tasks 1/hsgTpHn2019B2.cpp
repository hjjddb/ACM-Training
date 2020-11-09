#include<bits/stdc++.h>

using namespace std;

const int M = 1000 + 3;
int m, n;
int v[M], p[M];
int l, r, val;

int main(){
    freopen("CAU2.INP", "r", stdin);
    freopen("CAU2.OUT", "w", stdout);
    scanf("%d%d", &m, &n);
    for(int i = 1; i <= m; i++)
        scanf("%d", &p[i]);
    for(int i = 1; i <= n; i++){
        scanf("%d%d%d", &l, &r, &val);
        for(int j = 1; j <= m; j++)
            if (l <= p[j] && p[j] <= r)
                v[j] += pow(-1, (p[j] - l) % 2) * val; 
    }
    for(int i = 1; i <= m; i++)
        printf("%d\n", v[i]);
}