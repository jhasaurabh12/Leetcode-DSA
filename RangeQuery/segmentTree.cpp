#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
    int sz;
    vector<int> tree;
    vector<int> arr;
    int operate(int x, int y){
        return x+y;              //change here depending upon the query type
        // return min(x,y);
        // return max(x,y);
    }
    void buildSegTree(int treeIndex, int lo, int hi){
        if(lo==hi){
            tree[treeIndex]=arr[lo];
            return;
        }
        int mid=lo+(hi-lo)/2;
        buildSegTree(2*treeIndex+1,lo,mid);
        buildSegTree(2*treeIndex+2,mid+1,hi);
        tree[treeIndex]=operate(tree[2*treeIndex+1],tree[2*treeIndex+2]);
    }
    int queryRangeHelper(int lo, int hi, int l, int r, int treeIndex){
        //Case 1: If curr seg lies completely ouside the req seg 
        if(r<lo || l>hi)
            return 0;                               //change here depending upon the query

        //Case 2: if curr seg completely lies inside our req seg
        if(lo>=l && hi<=r)
            return tree[treeIndex];
        
        int mid=lo+(hi-lo)/2;
        int left=queryRangeHelper(lo,mid,l,r,2*treeIndex+1);
        int right=queryRangeHelper(mid+1,hi,l,r,2*treeIndex+2);
        return operate(left,right);
    }

    void updateHelper(int idx, int val, int lo, int hi, int treeIndex){
        if(lo==hi){
            tree[treeIndex]=val;
            arr[idx]=val;
            return;
        }
        int mid=lo+(hi-lo)/2;
        if(idx>mid)
            updateHelper(idx,val,mid+1,hi,2*treeIndex+2);
        else
            updateHelper(idx,val,lo,mid,2*treeIndex+1);
        tree[treeIndex]=tree[2*treeIndex+1]+tree[2*treeIndex+2];
    }
    public:
    SegmentTree(vector<int> &arr){
        int n=arr.size();
        sz=4*n;
        tree.resize(sz,0);
        this->arr=arr;
        buildSegTree(0,0,arr.size()-1);
    }

    int queryRange(int l, int r){
        return queryRangeHelper(0,arr.size()-1,l,r, 0);
    }

    void update(int idx, int val){
        updateHelper(idx,val,0,arr.size()-1,0);
    }
    
};
int main(){

    return 0;
}