#include<bits/stdc++.h>
using namespace std;

class SparseTable{

    vector<vector<int>> sp;
    vector<int> lg;
public:
    //also make changes here based upon the query type
    int operate(int x, int y){
        return max(x,y);
    }
    int operate(int x){
        return x;
    }
    void precomputeLog(int n){
        lg[1]=0;
        for(int i=2;i<=n;i++)
            lg[i]=lg[i/2]+1;
    }
    SparseTable(vector<int> &arr){
        int n=arr.size();

        lg.resize(n+1);
        precomputeLog(n);
        
        int k=lg[n];
        sp.resize(n,vector<int>(k+1,0));
        for(int i=0;i<n;i++)
            sp[i][0]=operate(arr[i]);
        //Here the j denotes the length 2^j, not the index 
        for(int j=1;j<=k;j++){
            for(int i=0;i+(1<<j)<=n;i++)
                sp[i][j]=operate(sp[i][j-1],sp[i+(1<<j-1)][j-1]);
        }
    }

    int rangeQuery(int i, int j){    //O(logn) query
        int len=j-i+1;
        //change this initial value based upon the query type
        //for sum, change it to 0
        //for  min, change it to INT_MAX
        //for max, change it to INT_MIN
        //for OR, change it to 0
        //for and, change it to INT_MAX

        int ans=INT_MIN;
        int idx=0;
        while(len>0){
            if(len&1){
                
                ans=operate(ans,sp[i][idx]);
                i+=(1<<idx);
            }
            idx++;
            len/=2;
        }
        return ans;
    }

    int rangeQueryIdemp(int i, int j){     //O(1) query
        int len=j-i+1;
        int idx=lg[len];

        return operate(sp[i][idx],sp[j-(1<<idx)+1][idx]);
    }
    
};
int main(){

    vector<int> arr={1,4,6,1,7,8};
    SparseTable queryDS(arr);
    for(int i=0;i<arr.size();i++){
        for(int j=i;j<arr.size();j++)
            cout<<i<<" "<<j<<" "<<queryDS.rangeQueryIdemp(i,j)<<endl;
    }
    // cout<<queryDS.rangeQuery(0,3)<<endl;
    return 0;
}