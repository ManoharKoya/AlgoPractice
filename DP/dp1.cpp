/*
    Count total number of N digit numbers such that the difference between 
    sum of even and odd digits is 1

*/
#include<bits/stdc++.h>
using namespace std;
unsigned long long int DP[50][1000][1000][2];
unsigned long long int dp(int n,int e,int o,bool isOdd){
    if(n<0) return 0;
    if(n==0 && (e-o)==1)  return 1;
    unsigned long long int f=0;
    if(DP[n][e][o][isOdd]!=-1) return DP[n][e][o][isOdd];
    if(isOdd) 
        for(int i=0; i<10; ++i) f+=dp(n-1, e, o+i, !isOdd);
    else 
        for(int i=0; i<10; ++i) f+=dp(n-1, e+i, o, !isOdd);
    return DP[n][e][o][isOdd]=f;
}
void solve(){
    int n; cin>>n;
    unsigned long long int ans = 0;
    for(int i=1; i<10; ++i) ans += dp(n-1,i,0,true); // should be from 1-9 not from 0-9
    cout<<ans<<'\n'; 
    return;
}
int main(){
    memset(DP, -1, sizeof(DP));
    solve();
    return 0;
}