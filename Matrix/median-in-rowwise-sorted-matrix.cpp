/*
This is a really good question of binary search. The question where we use multiple binary search.

The basic idea is that: Suppose x is the median of numbers, then count of numbers which are less than or equal to x is (n/2)+1, where n is odd.

Thus to find the number x which satisfies the above condition we will perform the binary search on our answer. Our answer will lie in the range
minvalue of matrix to maxvalue of matrix.

Also to find the count, we can use the binary search on each rows to find the count(x). 

*/
class Solution{   
public:
    int count(int target, vector<vector<int>> &matrix){
        
        int r=matrix.size();
        int c=matrix[0].size();
        int ans=0;
        for(int i=0;i<r;i++){
            int low=-1,high=c;
            while(low+1<high){
                int m=(low+high)/2;
                if(matrix[i][m]<=target)
                    low=m;
                else
                    high=m;
            }
            ans+=(low+1);
        }
        return ans;
    }
    int median(vector<vector<int>> &matrix, int r, int c){
        // code here
        int minValue=INT_MAX;
        int maxValue=INT_MIN;
        
        for(int i=0;i<r;i++)
            minValue=min(minValue,matrix[i][0]);
        
        for(int i=0;i<r;i++)
            maxValue=max(maxValue,matrix[i][c-1]);
            
 
        int low=minValue-1,high=maxValue+1;
        int total=r*c;
        while(low+1<high){
            int m=(low+high)/2;
            // cout<<m<<" "<<count(m,matrix)<<endl;
            if(count(m,matrix)<(total/2+1))
                low=m;
            else
                high=m;
        }
        return high;
    }
};