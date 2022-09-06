#include<bits/stdc++.h>

using namespace std;

class minHeap{
    int hSize;
    vector<int> arr;
    int currSize;

    int parent(int i){
        return i/2;
    }
    int left(int i){
        return 2*i;
    }
    int right(int i){
        return 2*i+1;
    }
public:
    void minHeapify(int i){
        int currInd=i;

        while(currInd<=currSize){
            pair<int,int> smallest=make_pair(arr[currInd],currInd);

            if(left(currInd)<=currSize)
                smallest=min(smallest,make_pair(arr[left(currInd)],left(currInd)));
            if(right(currInd)<=currSize)
                smallest=min(smallest,make_pair(arr[right(currInd)],right(currInd)));
            
            if(smallest.second==currInd)
                break;
            else{
                swap(arr[currInd],arr[smallest.second]);
                currInd=smallest.second;
            }
        }
    }
    minHeap(int n){
        currSize=0;
        hSize=n;
        arr.resize(hSize+1);
        arr[0]=0;
    }

    minHeap(vector<int> &elements){
        hSize=2*elements.size();
        arr.resize(hSize+1);
        for(int i=1;i<=elements.size();i++)
            arr[i]=elements[i-1];
        
        currSize=elements.size();
        for(int i=parent(currSize);i>=1;i--)
            minHeapify(i);
    }
    void insert(int x){
        if(currSize==hSize)
            throw "Heap is full. Can't insert any element";

        arr[currSize+1]=x;
        currSize++;
        int currInd=currSize;
        while(currInd!=1 && arr[parent(currInd)]>arr[currInd]){
            swap(arr[parent(currInd)],arr[currInd]);
            currInd=parent(currInd);
        }

    }

    int top(){
        if(currSize==0)
            throw "No elements present in heap";

        return arr[1];
    }

    void pop(){
        if(currSize==0)
            throw "No elements present in heap";
        
        arr[1]=arr[currSize];
        currSize--;
        int currInd=1;
        
        while(currInd<=currSize){
            pair<int,int> smallest={arr[currInd],currInd};
            if(left(currInd)<=currSize)
                smallest=min(smallest,make_pair(arr[left(currInd)],left(currInd)));
            
            if(right(currInd)<=currSize)
                smallest=min(smallest,make_pair(arr[right(currInd)],right(currInd)));
            if(smallest.first==arr[currInd])
                break;
            else{
                swap(arr[currInd],arr[smallest.second]);
                currInd=smallest.second;
            }
                
        }
    }

    bool empty(){
        return currSize==0;
    }
};
int main(){

    vector<int> arr={1,10,15,3,9,5};
    minHeap heap(arr);
    
    while(!heap.empty()){
        cout<<heap.top()<<endl;
        heap.pop();
    }
    return 0;
}
