class Solution {
public:
    int solveRec(int amount,int n,vector<int>& coins){
        if(amount==0) return 1;
        if(n==0) return 0;
        if(coins[n-1]<=amount)
           return solveRec(amount,n-1,coins)+solveRec(amount-coins[n-1],n,coins);
        else
           return solveRec(amount,n-1,coins);
    }
    int solveMem(int amount,int n,vector<int>& coins,vector<vector<int>>&dp){
        if(amount==0) return 1;
        if(n==0) return 0;
        if(dp[amount][n]!=-1) return dp[amount][n];
        int ans=0;
        if(coins[n-1]<=amount)
           ans=solveMem(amount,n-1,coins,dp)+solveMem(amount-coins[n-1],n,coins,dp);
        else
           ans=solveMem(amount,n-1,coins,dp);
        return dp[amount][n]=ans;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(amount+1,vector<int>(n+1,-1));
        //return solveRec(amount,n,coins);
        return solveMem(amount,n,coins,dp);
    }
};