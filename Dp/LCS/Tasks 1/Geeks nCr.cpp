// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// User function Template for C++
#define ar array
#define vt vector
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ll long long
#define ld long double
#define ii pair<int, int>
#define iii pair<int, ii>
#define vc vt<char>
#define vi vt<int>
#define vl vt<ll>
#define vvc vt<vc>
#define vvi vt<vi>
#define vvl vt<vl>
#define vii vt<ii>
#define fi first
#define se second
#define FORIT(i, s) for (auto it=(s.begin()); it!=(s.end()); ++it)
#define F_OR(i, a, b, s) for (int i=(a); (s)>0? i<(b) : i>(b); i+=(s))
#define F_OR1(n) F_OR(i, 0, n, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for(auto& x: a)

const int d4x[] = {-1, 0, 1, 0},
		d4y[] = {0, -1, 0, 1},
		d8x[] = {-1, -1, -1, 0, 0, 1, 1, 1},
		d8y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

template<class T1, class T2> istream &operator >>(istream &cin, pair<T1, T2> &x){
	cin >> x.fi >> x.se;
	return cin;
}

template<class T1, class T2> ostream &operator <<(ostream &cout, pair<T1, T2> x){
	cout << "(" << x.fi << "," << x.se << ")";
	return cout;
}

template<class T> istream &operator >>(istream &cin, vt<T> &v){
	FOR(v.size()) cin >> v[i];
	return cin;
}

template<class T> ostream &operator <<(ostream &cout, vt<T> &v){
	FOR(v.size()) cout << v[i] << " ";	
	cout << '\n';
	return cout;
}

const int MOD(1e9+7);

ll powM(int x, int k){
    if (!k) return 1;
    if (k==1) return x;
    ll half(powM(x, k>>1));
    return (k&1)? half*half%MOD*x%MOD : half*half%MOD;
}

class Solution{
public:
    int nCr(int n, int r){
        if (r>n) return 0;
        vl fac(n+1);
        fac[0]=1;
        FOR(i, 1, n+1) fac[i]=fac[i-1]*i%MOD;
        return int(fac[n]*powM(fac[r]*fac[n-r]%MOD, MOD-2)%MOD);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends