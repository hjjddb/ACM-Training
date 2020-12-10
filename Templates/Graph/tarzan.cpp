#include <bits/stdc++.h>

using namespace std;

const int nmax = 100000 + 3;

vector <int> a[nmax];
int n, m;
int cnt = 0;
vector <int> low(nmax, 0), num(nmax, 0);
stack <int> st;

void dfs(int u) {
    low[u] = num[u] = ++ cnt;
    st.push(u);
    for (int v: a[u]) {
        if (num[v]) low[u] = min(low[u], num[v]);
        else {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
    }

    if (num[u] == low[u]) {
        ++ cnt;
        int v;
        do {
            v = st.top();
            st.pop();
            low[v] = num[v] = INT_MAX;
        } while (v != u)
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0;i < m;++ i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
    }
    for (int i = 0;i < n;++ i) {
        if (!num[i]) dfs(i);
    }
    cout << cnt;
}