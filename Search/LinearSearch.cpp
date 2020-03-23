#include<bits/stdc++.h>
using namespace std;
bool LinearSearch(vector<int> a, int num){
    for(int i:a) if(i=num) return 1;
    return 0;
}
void solve(){
    int n,num; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    cin>>num;
    cout<<LinearSearch(a,num);
    return; 
}
int main(){
    solve();
    return 0;
}