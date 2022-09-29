#include<bits/stdc++.h>
using namespace std;
//it returns the kth smallest element

/* 
    also works on duplicate elements because it will basically find the element that will be present at (k-1)th position
    if the array was sorted hence doesnt matter if there are duplicate elements or not
*/

/*
    BEST CASE: O(N), when every partition divides the part of array in consideration into two halves
    WORST CASE: O(N^2), When the array is sorted in descending order and we want to find the 1st smallest element
*/
int partition(vector<int>&arr, int lo, int hi){
    //using random pivot;
    srand(time(0));
    int sz=hi-lo+1;
    int pivot=lo+rand()%sz;
    
    swap(arr[hi],arr[pivot]);

    int i=lo-1;
    for(int j=lo;j<=hi;j++){
        if(arr[j]<=arr[hi]){
            swap(arr[++i],arr[j]);
        }
    }
    return i;
}
int quickSelect(vector<int> arr, int k){
    int n=arr.size();
    int lo=0,hi=n-1;

    while(lo<=hi){
        int p=partition(arr,lo,hi);
        if(p==k-1)
            return arr[p];
        else if(p<k-1)
            lo=p+1;
        else
            hi=p-1;
    }
    return -1;
}
int main(){

    // for(int i=0;i<10;i++)
    vector<int> arr={4,2,3,16,7,4,1};
    for(int i=1;i<=arr.size();i++){
        cout<<quickSelect(arr,i)<<endl;
    }
    return 0;
}