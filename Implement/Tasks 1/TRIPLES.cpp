#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const int N = 200 + 2;
int n, a[N];
int res;
set<iii> triangle;

bool isTriangle(int x, int y, int z){
    return x + y > z && y + z >= x && z + x >= y;
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
            for(int k = j + 1; k <= n; k++)
                if (isTriangle(a[i], a[j], a[k]) && a[i] != a[j] && a[j] != a[k] && a[k] != a[i])
                    triangle.insert(iii(ii(a[i], a[j]), a[k]));
    cout << triangle.size() << '\n';
}

