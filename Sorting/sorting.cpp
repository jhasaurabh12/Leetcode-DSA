#include<bits/stdc++.h>
using namespace std;
class Sorting{
    int LomutoPartition(vector<int>&arr, int l, int h){
        int low=l-1;
        for(int j=l;j<=h;j++){
            if(arr[j]<=arr[h])
                swap(arr[++low],arr[j]);
        }
        return low;
    }
    void quickSortHelp(vector<int>&arr, int l ,int h){
        if(l>h)
            return;
        int p=LomutoPartition(arr,l,h);
        quickSortHelp(arr,l,p-1);
        quickSortHelp(arr,p+1,h);
    }
    void mergeArrays(vector<int>&arr,int l, int m,int h){
        int len=h-l+1;
        vector<int> temp(len);
        int k=0,i=l,j=m+1;
        while(i<=m||j<=h){
            if(j>h || (i<=m && arr[i]<=arr[j]))
                temp[k++]=arr[i++];
            else
                temp[k++]=arr[j++];
        }

        for(int p=l;p<=h;p++)
            arr[p]=temp[p-l];
    }
    void mergeSortHelp(vector<int>&arr, int l, int h){
        if(l>=h)
            return;
        int m=l+(h-l)/2;
        mergeSortHelp(arr,l,m);
        mergeSortHelp(arr,m+1,h);
        mergeArrays(arr,l,m,h);
    }

public:
    void quickSort(vector<int> &arr){
        //Not stable
        quickSortHelp(arr,0,arr.size()-1);
    }
    void mergeSort(vector<int> &arr){
        //stable
        mergeSortHelp(arr,0,arr.size()-1);
    }
    void insertionSort(vector<int>&arr)
    {
        //stable
        int n=arr.size();
        for(int i=1;i<n;i++)
        {
            int key=arr[i];
            int j=i-1;
            while(j>=0 && key<arr[j]){
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=key;
        }
    }
    void bubbleSort(vector<int>&arr){
        //stable
        int n=arr.size();
        for(int i=n-1;i>=0;i--){
            bool swapped=false;
            for(int j=0;j<i;j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                    swapped=true;
                }
                    
            }
            if(!swapped)
                return;
        }
    }
    void selectionSort(vector<int>&arr){
        //not stable
        // does the minimum memory writes
        int n=arr.size();
        for(int i=0;i<n;i++){
            int minIdx=i;
            for(int j=i+1;j<n;j++){
                if(arr[j]<arr[minIdx])
                    minIdx=j;
            }
            swap(arr[i],arr[minIdx]);
        }
    }
};
int main(){
    vector<int> arr={4,6,2,3,4,1,6,8};
    Sorting sort;
    sort.selectionSort(arr);
    for(auto x:arr){
        cout<<x<<" ";
    }
    return 0;
}