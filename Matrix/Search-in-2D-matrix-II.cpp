/*
The bruteforce solution for this problem is to iterate through the whole matrix and return true if target is present. But in this bruteforce approach we are not taking advantage of the fact of row-coloumn wise sorted matrix. we can use this fact to reduce our search space.

If we start on top-left corner of the matrix, towards right and towards down, both side the elements are increasing, thus we cannot make sure which side to move to search for target.

However if start on top-right corner of the matrix, towards down the elements are increasing and towards left elements are decreasing. Thus if target is larger than curr element, then we will move towards down and if target is smaller than curr element, then we will move towards left. This way at each step we are removing either the whole row or whole column from our search space.

TC:O(R+C) SC:O(1)

*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     
        int m=matrix.size();
        int n=matrix[0].size();
        
        int i=0,j=n-1;
        while(j>=0 && i<m){
            if(matrix[i][j]==target)
                return true;
            else if(target<matrix[i][j]){
                j--;
            }
            else
                i++;
        }
        return false;
    }
};