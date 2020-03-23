#include<bits/stdc++.h>
using namespace std;
#define lli long long int 
#define NA(i,s,n) for(lli i=s; i<n; ++i)

lli nc2(lli n, lli ind, vector<lli> &rs){
    rs[ind] = (n*(n-1))/2;
    return rs[ind];
}
lli nc2(lli n){
    if(n<0) return 0;
    return (n*(n-1))/2;
}
int main(){
    lli n,tp,res=0; cin>>n;
    vector<lli> a(n+1),ct(n+1,0),rs(n+1);
    NA(i,1,n+1) cin>>a[i], ct[a[i]]++;
    NA(i,1,n+1) res+=nc2(ct[i], i, rs);
    NA(i,1,n+1){
        tp = res - rs[a[i]] + nc2(ct[a[i]]-1);
        cout<<tp<<'\n';
    }
    return 0;
}
