class Solution {
public:
    int dp[46];
    int solveRec(int n){
        if(n==0 || n==1) return 1;
        return solveRec(n-1)+solveRec(n-2);
    }
    int solveMem(int n){
        if(n==0 || n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=solveMem(n-1)+solveMem(n-2);
    }
    int climbStairs(int n) {
       memset(dp,-1,sizeof(dp));
       return solveMem(n);
    }
};