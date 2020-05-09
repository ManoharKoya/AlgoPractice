#include<bits/stdc++.h>
#define pb push_back
using namespace std;

class ArtPoint{
    public:
    vector<int> gp[100002], res, lows, ids;
    vector<bool> vis, isArt;
    int outEdges = 0, n, m, a, b, id = 0;
    ArtPoint(){
        cin>>n>>m; 
        for(int i=0; i<m; ++i) cin>>a>>b, gp[a].pb(b), gp[b].pb(a);
        lows.resize(n); ids.resize(n); vis.resize(n); isArt.resize(n);
        for(int i=0; i<n; ++i) lows[i] = i, ids[i] = i, vis[i] = 0, isArt[i] = 0; 
        FindArtPoints();
    }
    void dfs(int nd, int par, int rt){
        if(nd==rt) ++outEdges;
        vis[nd] = 1; 
        ids[nd] = id; lows[nd] = id++; 
        for(int i:gp[nd]){
            if(i==par) continue;
            if(!vis[i]){
                dfs(i, nd, rt);
                lows[nd] = min(lows[nd], lows[i]);
                if(ids[nd]<=lows[i]) isArt[nd] = 1;
            } else {
                lows[nd] = min(lows[nd], ids[i]);
            }
        }
        return;
    }
    void FindArtPoints(){
        for(int i=0; i<n; ++i) if(!vis[i]) outEdges = 0, dfs(i,-1,i), isArt[i] = (outEdges > 1);
        for(int i=0; i<n; ++i) if(isArt[i]) cout<<i<<' ';
        return;
    }
};
int main(){
    ArtPoint *p = new ArtPoint();
    return 0;
}