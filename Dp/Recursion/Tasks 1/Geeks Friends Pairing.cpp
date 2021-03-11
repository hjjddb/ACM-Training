// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        sort(arr, arr+N);
        int sum(0);
        for(int i=0; i<N; ++i) sum+=arr[i];
        vector<int> dp(sum+1);
        dp[0]=1;
        for(int i=arr[0]; i<=sum; ++i) for(int j=0; j<N; ++j) dp[i]+=dp[i-arr[j]];
        return *max_element(dp.begin(), dp.end())>1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends