#include<bits/stdc++.h>
using namespace std;
bool JumpSearch(vector<int> a, int num){
    int n = a.size(), m = sqrt(n);
    for(int i=0; i<n; i+=m){
        if(a[i]==num) return 1;
        else if(a[i]>num){
            for(int j=0; j<m; ++j) if(a[i-j]==num) return 1;
        }
        if(i+m>n) for(int j=i; j<n; ++j) if(a[j]==num) return 1;
    }
    return 0;
}
void solve(){
    int n,num; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    sort(a.begin(),a.end());
    for(int i=1; i<n+1; ++i){
        // cin>>num;
        cout<<JumpSearch(a,i);
    }
    return; 
}
int main(){
    solve();
    return 0;
}