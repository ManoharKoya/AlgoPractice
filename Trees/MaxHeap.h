#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
    public:
    // can be array impl (or) can be tree impl
    vector<int> heapArray; // 0 indexed array
    int getPar(int ind){
        ind--;
        return heapArray[ind/2];
    }
    int getRchild(int ind){
        return heapArray[2*ind + 2];
    }
    int getLchild(int ind){
        return heapArray[2*ind + 1];
    }
    void insert(int val){
        heapArray.push_back(val);
        int curInd = heapArray.size()-1;
        while(curInd>0 && getPar(curInd)<val){
            swap(heapArray[curInd], heapArray[(curInd-1)/2]);
            curInd--, curInd/=2;
        }
        return;
    }
    int del(){
        if(!heapArray.size()) return -1;
        int res = heapArray[0];
        swap(heapArray[0], heapArray[heapArray.size()-1]);
        heapArray.pop_back();
        int curInd = 0;
        while(curInd*2+2<heapArray.size() && heapArray[curInd] < max(heapArray[curInd*2 + 1], heapArray[curInd*2 + 2])){
            if(heapArray[curInd*2 + 1] > heapArray[curInd*2 + 2]) 
                swap(heapArray[curInd], heapArray[curInd*2+1]), curInd = curInd*2 + 1;
            else swap(heapArray[curInd], heapArray[curInd*2 +2]), curInd = curInd*2 + 2;
        }
        if(curInd*2+1 < heapArray.size() && heapArray[curInd*2+1]>heapArray[curInd]) {
            swap(heapArray[curInd*2+1], heapArray[curInd]);
            curInd = curInd*2 + 1;
        }
        return res;
    }
    vector<int> heapify(vector<int> &a){
        for(int i=a.size()-1; i>=0; i--){
            int cur = i,prev;
            while(cur*2+1<a.size()){
                if(cur*2+1<a.size() && cur*2+2<a.size() && max(a[cur*2+1],a[cur*2+2])>a[cur]){
                    if(a[cur*2+1]>a[cur*2+2]) swap(a[cur],a[cur*2+1]), cur=cur*2+1;
                    else swap(a[cur], a[cur*2+2]), cur=cur*2+2;
                } else if(cur*2+1==a.size()-1 && a[cur*2+1]>a[cur]) {
                    swap(a[cur], a[cur*2+1]), cur=cur*2+1;
                }
                else break;
            }
        }
        return a;
    }
};