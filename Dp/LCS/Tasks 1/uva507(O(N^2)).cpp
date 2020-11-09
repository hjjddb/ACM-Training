// đ hiểu sao mất có hơn 2s :)
#include<bits/stdc++.h>

using namespace std;

const int N = 20007;
int T, n;
int a[N], d[N];
int start, stop;
int ans;

int main(){
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
        ans = 0;
        d[0] = 0;
        start = 0;
        stop = 0;
        scanf("%d", &n);
        for(int i = 1; i < n; i++){
            scanf("%d", &a[i]);
            d[i] = d[i - 1] + a[i];
        }
        for(int i = 1; i < n; i++)
            for(int j = i; j < n; j++){
                int tmp = d[j] - d[i - 1];
                if (ans <= tmp){
                    if (ans < tmp){
                        start = i;
                        stop = j + 1;
                        ans = tmp;
                    }
                    else{
                        if (stop - start <= j + 1 - i){
                            if (stop -  start < j + 1 - i){
                                stop = j + 1;
                                start = i;
                            }
                            else{
                                if (j + 1 < stop){
                                    stop = j + 1;
                                    start = i;
                                }
                            }
                        }
                    }
                }
            }
        if (ans > 0)
            printf("The nicest part of route %d is between stops %d and %d\n", t, start, stop);
        else 
            printf("Route %d has no nice parts\n", t);
    }
}
