#include<bits/stdc++.h>
#include "MaxHeap.h"
using namespace std;
void solve_N_KlogN(int n, int k, vector<int> &a){
    int n,k; cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    MaxHeap h;
    h.heapArray = h.heapify(a); // O(n).
    for(int i=0; i<k-1; ++i) h.del(); // O(k.logn).
    cout<<h.heapArray[0]<<'\n';
    return;
}
void solve_N(int n, int k, vector<int> &a){
    
    return; 
}
int main(){
    int n,k; cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin>>a[i]; 
    solve_N_KlogN(n,k,a);
    return 0;
}