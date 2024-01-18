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
    int solveTab(int n){
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    int climbStairs(int n) {
       memset(dp,0,sizeof(dp));
       return solveTab(n);
    }
};