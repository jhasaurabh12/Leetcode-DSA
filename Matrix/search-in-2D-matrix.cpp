/*
Let's think this problem in this way. Suppose if somehow we are able to find the row in which our target might lie, then we can simply find the exact position of target in that row by performing the binary search over that row.

So far so good, right? Now our task is to efficiently finding the row in which our target element might lie. So How do we do that?

For now, consider a function F(i) which returns true if the largest element in the ith row is greater than or equal to our target element, else False

Now consider a matrix given below with target element as 34, and for each row will mention the value of F(i). You can see the function F(i) is a monotonic function and wherever you see the monotonic function, just close your eyes and apply the binary search technique on that.

Thus our time complexity is O(log(m)+log(n))= O(log(mn)) and space complexity: O(1)
log(m) -> for finding the row in which target might lie,
log(n) -> for finding the element in that row using binary search.



*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int rows=matrix.size();
        int cols=matrix[0].size();
        
        //first we will find the row in which our target might lie using binary search
        
        int l=-1,r=rows;
        while(l+1<r){
            int m=(l+r)/2;
            
            if(matrix[m][cols-1]>=target)
                r=m;
            else
                l=m;
        }
        if(r==rows)
            return false; // element is greatest than all elements of matrix
        
        //now searching in a particular row
        int low=-1,high=cols;
        while(low+1<high)
        {
            int m=(low+high)/2;
            if(matrix[r][m]==target)
                return true;
            else if(matrix[r][m]<target)
                low=m;
            else
                high=m;
        }
        return false;
    }
};