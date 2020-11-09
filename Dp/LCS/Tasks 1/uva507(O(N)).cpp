#include<bits/stdc++.h>

using namespace std;

const int N = 20007;
int T, n;
int a[N], d[N];
int start, stop;
int startRes, stopRes;
int ans;

int main(){
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
        ans = -1;
        d[0] = 0;
        start = 1;
        stop = 0;
        startRes = 0;
        stopRes = 0;
        scanf("%d", &n);
        for(int i = 1; i < n; i++)
            scanf("%d", &a[i]);
    
        int tmpRes = 0, res = -1;
        for(int i = 1; i < n; i++){
            tmpRes += a[i];
            if (ans <= tmpRes){
                if (ans < tmpRes){
                    ans = tmpRes;
                    startRes = start;
                    stopRes = i + 1;
                }
                else{
                    if (stopRes - startRes <= i + 1 - start){
                        if (stopRes - startRes < i + 1 - start){
                            stopRes = i + 1;
                            startRes = start;
                        }
                        else{
                            if (stopRes > i + 1){
                                stopRes = i + 1;
                                startRes = start;
                            }
                        }
                    }
                }
            }
            if (tmpRes < 0){
                start = i + 1;
                tmpRes = 0;
            }
        }
            
        if (ans > 0)
            printf("The nicest part of route %d is between stops %d and %d\n", t, startRes, stopRes);
        else 
            printf("Route %d has no nice parts\n", t);
    }
}
