#include<bits/stdc++.h>

using namespace std;

const int N = 1000000 + 6;
int n, a[N];
set<int> num;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        num.insert(a[i]);
    }
    printf("%d", num.size());
}