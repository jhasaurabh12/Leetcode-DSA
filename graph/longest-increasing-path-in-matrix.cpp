/*
->The brute-force way to solve this problem is by doing the dfs to find the longest increasing path in matrix starting from each point in the matrix. 

->Here while doing the dfs we don't need to keep track of visited cells in the matrix. Because the cells in the matrix are connected as DAG(directed acyclic graph). Hence we are never gonna enter a cycle, thus won't lead to infinite loop of dfs.

->Also if we observe properly, while doing the dfs we are doing the recalculation of some of the subproblems. Hence we can think of applying memoization. But generally when we have to visit the cells in 4 directions, we can't memoize the solution of subproblem because solution might be interdependent on each other and we might enter a deadlock. Consider the following example of 2X2 matrix example.
    1 2     -> here dp[0][0] depends on dp[0][1] and dp[1][0]
    3 4         but dp[0][1] depends on dp[0][0] and dp[1][1]. 
                thus, dp[0][0] and dp[0][1] enters in deadlock.

But if we consider the current problem, we have DAG. Thus we won't enter in the deadlock because we will only look at the neighbours which are greater than current cell, thus if current cell ans depends on neighbouring cell then neighbouring cell ans won't depend on current cell, because we want stricly increasing path. If we consider the above example of 2X2.
        dp[0][0] depends on dp[1][0] and dp[0][1]. because mat[1][0] and mat[0][1] greater than mat[0][0]
        dp[0][1] depends only on dp[1][1]. Thus no deadlock is present.
        
Thus this is rare of a question where we are able to memoize our dfs solution because of the property of DAG(Directed acyclic graph).

Key points learnt from this question:
-> if we have DAG, then no need to keep track of visited nodes/cells. Because we are never gonna enter infinte loop of dfs due to absence of cycle.
->If we have DAG and if we have overlapping subproblems then we can memoize dfs solution

*/




int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
class Solution {
public:

    int dfs(int i,int j,vector<vector<int>> &matrix, vector<vector<int>> &dp){
        if(dp[i][j]>0) return dp[i][j];
        
        dp[i][j]=1;
        for(int k=0;k<4;k++){
            int ni=i+dir[k][0];
            int nj=j+dir[k][1];
            
            if(ni>=0 && nj>=0 && ni<matrix.size() && nj<matrix[0].size() && matrix[ni][nj] > matrix[i][j]){
                dp[i][j]=max(dp[i][j],1+dfs(ni,nj,matrix,dp));
            }
        }
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        
        int ans=1;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                ans=max(ans,dfs(i,j,matrix,dp));
            }
        }
        return ans;
    }
};