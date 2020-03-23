#include<bits/stdc++.h>
using namespace std;
int n,k;
int hashFun(string p, int prev, int ind){
    if(ind==0){
        int res = 0;
        for(int i=0; i<k; ++i) res += ((p[i]-'a')*pow(26,k-i-1));
        return res;
    }
    int res = prev;
    res -= ((p[ind-1]-'a')*pow(26,k-1));
    res += (p[ind+k]-'a');
    return res;
}
bool check(string p, string s, int ind){
    for(int i=0; i<k; ++i) if(s[ind+i]!=p[i]) return 0;
    return 1;
}
int main(){
    string s,p;
    cin>>s>>p;  
    n=s.length(), k = p.length();
    int hs = hashFun(p, -1, 0);
    int prev = -1;
    for(int i=0; i<n-k; ++i){
        prev = hashFun(s, prev, i);
        if(hs==prev) {
            cout<<"YES "<<i<<'\n';
            if(check(p,s,i)) 
                {cout<<"YES\n"; return 0;}
        }
    }
    cout<<"NO\n"; 
    return 0;
}