/* 
    MAX sub array sum 
        KADANE'S Algorithm():
            max_end_here = 0
            max_so_far = 0
            for i in arr:
                max_end_here += i
                max_end_here = max(0,max_end_here)
                max_so_far = max(max_so_far, max_end_here)
            return max_so_far
*/
#include<bits/stdc++.h>
#define lli long long int
#define NA(i,s,n) for(lli i=s; i<n; ++i)
using namespace std;
lli Kadanes(vector<lli> a){
    lli res = 0, max_here=0;
    for(lli i:a){
        max_here += i;
        max_here = max(max_here, (long long)(0));
        res = max(res, max_here);
    }
    return res;
}
int main(){
    lli n; cin>>n;
    vector<lli> a(n);
    NA(i,0,n) cin>>a[i];
    cout<<Kadanes(a);
    return 0;
}