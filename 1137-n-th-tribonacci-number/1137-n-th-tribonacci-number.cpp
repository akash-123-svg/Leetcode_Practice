class Solution {
public:
    int solveMemo(int n,vector<int>&dp){
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=solveMemo(n-1,dp)+solveMemo(n-2,dp)+solveMemo(n-3,dp);
    }
    int tribonacci(int n) {
      // if(n==0) return 0;
      // if(n==1 || n==2) return 1;
      // else return tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
        vector<int> dp(n+1,-1);
        return solveMemo(n,dp);
    }
};