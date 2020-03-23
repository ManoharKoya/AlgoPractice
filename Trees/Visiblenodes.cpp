#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define NA(i,s,n) for(int i=s; i<n; ++i)
vector<int> gp[1000],res,vis;
int n; // no. of edges.
// visNodes - if there isn't any node greater than 'v' in path from root to 'v' then 'v' is visNode.
void visNodes(int nd, int rt, int mxUpto){ // same as dfs.
    vis[nd]=1;
    for(int i:gp[nd]){
        if(i!=rt && !vis[i]) {
            if(i>mxUpto) res.pb(i);
            int newMx = max(i,mxUpto);
            visNodes(i,nd, newMx);
        }
    }
    return;
}
void solve(){
    int a,b; cin>>n;
    vis.resize(n+1,0);
    NA(i,0,n) cin>>a>>b, gp[a].pb(b), gp[b].pb(a);
    res.pb(1);
    visNodes(1,0,1);
    for(int i:res) cout<<i<<' ';
    return;
}
int main(){
    solve();
    return 0;
}