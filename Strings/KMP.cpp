#include<bits/stdc++.h>
using namespace std;
vector<int> buildLPS(string p){
    int i=0,cur=0;
    vector<int> lps(p.length());
    lps[0] = -1; ++i;
    while(i!=p.length()){
        if(p[i]==p[cur]) lps[i]=cur, ++cur;
        else lps[i]=-1, cur=0;
        ++i;
    }
    return lps;
}
int main(){
    string s,p; cin>>s>>p;
    int n=s.length(), m = p.length();
    vector<int> lps = buildLPS(p);
    int i=0, j=-1;
    while(j<m && i<=n){
        if(j==m-1) {cout<<"YES\n"; return 0;}
        if(p[j+1]==s[i]) ++j, ++i;
        else {
            if(j!=-1) j=lps[j];
            else ++i;
        } 
    }
    cout<<"NO\n";
    return 0;
}