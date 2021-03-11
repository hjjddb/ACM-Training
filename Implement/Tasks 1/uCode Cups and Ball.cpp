#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    
    int ans(1);
    for(int i=0; i<s.size(); ++i){
        if (ans==1){
            if (s[i]=='A') ans=2;
            else if (s[i]=='C') ans=3;
        } else if (ans==2){
            if (s[i]=='A') ans=1;
            else if (s[i]=='B') ans=3;
        } else if (ans==3){
            if (s[i]=='B') ans=2;
            else if (s[i]=='C') ans=1;
        }
    }
    cout << ans;
}