#include<bits/stdc++.h>
using namespace std;
bool binSearch(vector<int> a, int num){
    int l=0, r = a.size()-1, mid;   
    while(1){
        if(l>r) return 0;
        mid = (l+r)/2;
        if(a[mid]==num) return 1;
        else if(a[mid]<num) l=mid+1;
        else r=mid-1;
    }
}
void solve(){
    int n,num; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    sort(a.begin(),a.end());
    cin>>num;
    cout<<binSearch(a,num);
    return; 
}
int main(){
    solve();
    return 0;
}