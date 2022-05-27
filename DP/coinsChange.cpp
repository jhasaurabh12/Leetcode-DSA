class Solution {
public:
    //Recursive + memoization
    int minCoins(int n, int amount, vector<int>&coins,vector<vector<int>> &dp){
        if(amount==0)
            return 0;
        if(n==0)
            return INT_MAX;
        
        if(dp[n][amount]!=-1)
            return dp[n][amount];
        
        int taken=INT_MAX,notTaken=INT_MAX;
        
        if(amount>=coins[n-1])
            taken=minCoins(n,amount-coins[n-1],coins,dp);
        
        taken=taken==INT_MAX?INT_MAX:taken+1;
        notTaken=minCoins(n-1,amount,coins,dp);
        return dp[n][amount]=min(taken,notTaken);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        
        //Recursive + memoization solution
        // vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        // int ans=minCoins(coins.size(),amount,coins,dp);
        // return ans==INT_MAX?-1:ans;
        
        //iterative dp
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,0));
        int n=coins.size();
        for(int i=1;i<=amount;i++){
            dp[0][i]=INT_MAX;
        }
        
        //dp[i][j] gives the minimum number of coins req to create a change of 
        //.        amount j using first (i) coins given in coins array
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
             
                int take=INT_MAX,notTake=INT_MAX;
                if(j>=coins[i-1])
                    take=dp[i][j-coins[i-1]];
                take=take==INT_MAX ? INT_MAX:take+1;
                notTake=dp[i-1][j];
                dp[i][j]=min(take,notTake);
            }
        }
        return dp[n][amount]==INT_MAX?-1:dp[n][amount];
    }
};