#include<bits/stdc++.h>
#define lli long long int
#define NA(i,s,n) for(lli i=s; i<n; ++i)
using namespace std;
struct node{
    node* a[26];
    bool eof;
};
node* getTrie(){
    struct node* t = new node;
    t->eof=false;
    NA(i,0,26) t->a[i]=NULL;
    return t;
}
void insert(node *root, string s){
    node *cur = root;
    for(char i:s){
        if(cur->a[i-'a']==NULL) cur->a[i-'a']=getTrie();
        cur=cur->a[i-'a'];
    }
    cur->eof=true;
    return;
}
bool search(node *root, string s){
    node *cur = root;
    for(char i:s){
        if(cur->a[i-'a']==NULL) return 0; 
        cur = cur->a[i-'a'];
    }
    if(cur->eof) return 1;
    return 0;
}
void solve(){
    lli n; cin>>n; string s;
    node* root = getTrie();
    NA(i,0,n) cin>>s, insert(root, s);
    lli q; cin>>q;
    NA(i,0,q) cin>>s, (search(root, s)) ? cout<<"YES\n" : cout<<"NO\n";
    return;
}
int main(){
    solve();
    return 0;
}