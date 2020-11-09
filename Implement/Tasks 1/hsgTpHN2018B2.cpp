#include<bits/stdc++.h>

using namespace std;

const int N = 300000 + 5;
int n;
int a[N];
set<int> s;
int res;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        if (s.count(-a[i]))
            res++;
        s.insert(a[i]);
    }
    printf("%d\n", res);
}