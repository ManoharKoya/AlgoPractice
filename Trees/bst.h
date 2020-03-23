#include<bits/stdc++.h>
using namespace std;

struct bst_node{
    struct bst_node * left=NULL;
    struct bst_node * right=NULL;
    int val;
};
class bst{
    struct bst_node* root;
    public:
        bst(){
            root=NULL;
        }
        bool isEmpty(){
            if(root==NULL) return true;
            return false;
        }
        void insert(int n){
            struct bst_node* cur = root;
            struct bst_node* par = new bst_node;
            struct bst_node* parent=NULL;
            par->left=NULL, par->right=NULL, par->val = n;
            while(cur!=NULL) {
                parent = cur;
                if(cur->val < n) cur=cur->right;
                else cur=cur->left;
            }
            if(parent==NULL) root=par;
            else if(parent->val < n) parent->right=par;
            else parent->left = par;
            return;
        }
        void printBST(bst_node* p){
            if(p->left!=NULL)  printBST(p->left);
            cout<<p->val<<' ';
            if(p->right!=NULL) printBST(p->right);
            return;
        }
        void printBST(){ 
            printBST(root); 
            return;
        }
};
