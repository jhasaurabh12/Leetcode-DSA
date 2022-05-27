class Solution {
public:
//     int totalWays(int i, int j, vector<vector<int>>&grid){
//         if(i==grid.size() || j==grid[0].size() || grid[i][j]==1)
//             return 0;
        
//         if(i==grid.size()-1 && j==grid[0].size()-1)
//             return 1;
        
//         return totalWays(i+1,j,grid) + totalWays(i,j+1,grid);
//     }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        
        vector<vector<long long int>> dp(n,vector<long long int>(m,0));
    
        dp[n-1][m-1]=obstacleGrid[n-1][m-1] ? 0:1;
        for(int i=n-2;i>=0;i--){
            if(obstacleGrid[i][m-1])
                dp[i][m-1]=0;
            else
                dp[i][m-1]=dp[i+1][m-1];
        }
        
        for(int j=m-2;j>=0;j--){
            if(obstacleGrid[n-1][j])
                dp[n-1][j]=0;
            else
                dp[n-1][j]=dp[n-1][j+1];
        }
        for(int i=n-2; i>=0; i--){
            for(int j=m-2;j>=0;j--){
                
                // cout<<i<<" "<<j<<endl;
                if(obstacleGrid[i][j]==1)
                    dp[i][j]=0;
                else
                    dp[i][j]=dp[i+1][j] +dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};