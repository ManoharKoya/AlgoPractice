/*
    Given an algebraic expression of the form (x1 + x2 + x3 + . . . + xn) * (y1 + y2 + . . . + ym) and
(n + m) integers. Find the maximum and minimum value of the expression using the given
integers.
    --> solution 
    --> totalsum = S
    --> X - Sum of n integers.
    --> (S-x) - Sum of remaining imtegers.
    --> Iterate over all possible values of 'X' then keep track of 
        min(X.(S-X)) and max(X.(S-X)).
    ***implement_correctly***
*/
#include<bits/stdc++.h>
#define lli long long int
#define NA(i,s,n) for(lli i=s; i<n; ++i)
using namespace std;
lli s=0,mn=1e10+1,mx=0;
// dp[rem][ind]
void fun1(lli sm, lli n, vector<lli> a,lli ind){
    if(n<0 || ind>=a.size()) return;
    if(n==0) {mn=min(mn,sm*(s-sm)), mx=max(mx,sm*(s-sm)); return;}
    fun1(sm+a[ind],n-1,a,ind+1);
    fun1(sm,n, a,ind+1);
    return;
}
vector<lli> res;
lli dp[100][51];
lli fun(lli rem, lli ind, vector<lli> a, lli sm){
    if(ind>=a.size()) return 0;
    if(dp[rem][ind]!=-1) return dp[rem][ind];
    if(rem==0) {res.push_back(sm); return dp[rem][ind]=sm;}
    return fun(rem-1, ind+1, a, sm+a[ind]) + fun(rem, ind+1, a, sm);
}
void solve(){
    lli n,m; cin>>n>>m;
    vector<lli> a(n+m);  
    NA(i,0,n+m) cin>>a[i], s+=a[i];
    fun1(0,n,a,0);
    cout<<mn<<' '<<mx;
    return;
}
int main(){
    solve();
    return 0;
}