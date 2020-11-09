#include <bits/stdc++.h>

#define nmax 200005

using namespace std;

int n, m;
int b[nmax];
int a[nmax];
map<int, int> c;

void input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        c[b[i]]++;
    }

    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
    }
    sort(b + 1, b+n+1);
}

int bs(int x)
{
    // int val = lower_bound(b+1, b+n+1, x);

    int r = n, l = 0;
    while (r-l > 1)
    {
        int m = (r+l)/2;
        if (b[m] > x) r = m;
            else if (b[m] < x) l = m;
                else r = l = m; 
    }
    if (b[r] <= x) return r;
        else if (b[l] <= x) return l;
            else return -1; 
}

void process()
{
    for (int i = 1; i <= m; i++)
    {
        auto tmp = c.lower_bound(a[i]);
        if (tmp->first > a[i] && tmp == c.begin())
        {
            cout << "-1\n";
            continue;
        }
        if (tmp->first > a[i]) --tmp;
        int val = tmp->first;
        cout << val << "\n";
        if (c[val] <= 1) c.erase(val);
            else c[val]--;
    }

}

int main(int argc, char const *argv[])
{
    input();
    process();
    return 0;
}
