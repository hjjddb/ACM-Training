#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;

const int BASE = 100000;

struct BigNum{
    int pos;
    vl val;

    BigNum(){
        pos = 0;
        val.resize(0);
    }

    BigNum(int x){
        if (x >= 0) 
            pos = 0;
        else{
            pos = 1;
            x = abs(x);
        }
        while(x > 0){
            val.push_back(x % BASE);
            x /= BASE;
        }
    }

    void fix(){
        val.push_back(0);
        for(int i = 0; i < val.size() - 1; i++){
            val[i + 1] += (val[i] / BASE);
            val[i] %= BASE;
            if (val[i] < 0){
                val[i] += BASE;
                val[i + 1]--;
            }
        }
        while(val.back() >= BASE){
            val.push_back(val.back() / BASE);
            val[val.size() - 2] %= BASE;
        }
        while(val.size() >= 2 && val.back() == 0) 
            val.pop_back();
    }

    void operator += (const BigNum &b){
        val.resize(max(val.size(), b.val.size()));
        for(int i = 0; i < val.size(); i++)
            val[i] += b.val[i];
        fix();
    }

    void operator *= (int x){
        if (x == 0) 
            pos = 0;
        else 
            pos = (pos + int(!(x >= 0))) % 2;
        x = abs(x);
        for(int i = 0; i < val.size(); i++){
            val[i] *= x;
        }
        fix();
    }

    bool operator < (const BigNum &b){
        if (pos != b.pos) return pos > b.pos;
        if (pos == 0){
            if (val.size() != b.val.size()) 
                return val.size() < b.val.size();
            for(int i = val.size() - 1; i >= 0; i--){
                if (val[i] != b.val[i])
                    return val[i] < b.val[i];
            }
            return false;
        }
        else{
            if (val.size() != b.val.size()) 
                return val.size() > b.val.size();
            for(int i = val.size() - 1; i >= 0; i--){
                if (val[i] != b.val[i])
                    return val[i] > b.val[i];
            }
            return false;
        }
    }

    void print(){
        if (pos == 1)
            printf("-");
        printf("%d", val.back());
        for(int i = val.size() - 2; i >= 0; i--)
            printf("%05d", val[i]);
    }

    void operator /= (int x){
        pos = (pos + int(!(x >= 0))) % 2;
        if (x < 0) x = abs(x);
        for(int i = val.size() - 1; i > 0; i--){
            val[i - 1] += (val[i] % x) * BASE;
            val[i] /= x;
        }
        val[0] /= x;
        fix();
    }
};

BigNum add(BigNum a, BigNum b){
    BigNum c;
    a.val.resize(max(a.val.size(), b.val.size()));
    b.val.resize(max(a.val.size(), b.val.size()));
    // c.val.resize(b.val.size());
    int tmp1 = 0;
    for(int i = c.val.size() - 1; i >= 0; i--){
        int tmp = a.val[i] + b.val[i];
        c.val.push_back((tmp + tmp1) % BASE);
        tmp1 = (tmp + tmp1)/BASE;
    }
    if (tmp1 != 0)
        c.val.push_back(tmp1);
    return c;
}

BigNum operator * (BigNum x, int k){
    BigNum res = x;
    res.pos = (res.pos + int(!(k >= 0))) % 2;
    k = abs(k);
    for(int i = 0; i < res.val.size(); i++){
        res.val[i] *= k;
    }
    res.fix();
    return res;
}

int main(){
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int x, t = 0;
    int a[107];
    int n = 0;
    while(scanf("%d", &x) > 0){
        t++;
        a[++n] = x;
        while(scanf("%d", &x) > 0){
            if (x != -999999){
                a[++n] = x;
            }
            else{
                break;
            }
        }
        int m = 1;
        vector<int> arr[110];
        for(int i = 1; i <= n; i++){
            if (a[i] == 0){
                arr[++m].push_back(0);
                m++;
            }
            else
                arr[m].push_back(a[i]);
        }
        BigNum ans;
        ans.pos = -1;
        for(int l = 1; l <= m; l++){
            if (!arr[l].empty()){
                int nSize = arr[l].size();
                BigNum dp[nSize + 1];
                dp[0] = BigNum(1);
                for(int i = 1; i <= nSize; i++)
                    dp[i] = dp[i - 1] * arr[l][i - 1];
                if (dp[nSize].pos){
                    BigNum tmp1 = dp[nSize];
                    int i = 0;
                    while(arr[l][i] > 0 && i < nSize){
                        tmp1 /= arr[l][i];
                        // tmp1.print();
                        // printf("\n");
                        i++;
                    }
                    if (i < nSize && nSize > 1){
                        tmp1 /= arr[l][i];
                        tmp1.pos = 0;
                    }
                    // tmp1.print();
                    // printf("\n");
                    BigNum tmp2 = dp[nSize];
                    i = nSize - 1;
                    while(arr[l][i] > 0 && i >= 0){
                        tmp2 /= arr[l][i];
                        i--;
                    }
                    if (i >= 0 && nSize > 1){
                        tmp2 /= arr[l][i];
                        tmp2.pos = 0;
                    }
                    if (tmp1 < tmp2) 
                        tmp1 = tmp2;
                    if (ans.pos == -1) ans = tmp1;
                    else 
                        if (ans < tmp1)     
                            ans = tmp1;        
                }
                else{
                    if (ans.pos == -1) 
                        ans = dp[nSize];
                    else 
                        if (ans < dp[nSize])
                            ans = dp[nSize];
                }
            }
        }
        ans.print();
        printf("\n");
        n = 0;
    }
}