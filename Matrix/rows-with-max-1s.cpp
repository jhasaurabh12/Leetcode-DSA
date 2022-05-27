/*
First approach is the bruteforce way, where iterate through each row and
get the count of ones, if curr count is greater than max count then we update our
ans with curr row number. Finally return the ans.
TC:O(n*m), SC:O(1)

Second approach is using the binary search. We use binary search in each row to
find the count of ones. and use the similiar procedure as mentioned above.
TC:O(n*logm) SC:O(1)

This approach is based upon the idea that, if curr row has first appearance of "1"
at jth index, then in the next row we need to check if there is "1" at (j-1)th index
and if it is  then find the first appearance of "1" between [0,j-1] and similarly
peform the same steps as mentioned above for the next rows.
Thus it is based upon idea that if we already found a row with count of "1" as x,
then in next row we will only care about if we have "1" having count>x

*/
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int j=m-1;
	    int row=0;
	    for(int i=0;i<n && j>=0;i++){
	        if(arr[i][j]){
	            row=i;
	            while(arr[i][j] && j>=0)
	                j--;
	        }
	    }
	    return j==m-1 ? -1:row;
	}

};