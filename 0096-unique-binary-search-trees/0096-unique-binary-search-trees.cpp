class Solution {
public:
    int dp[20];
    int solveRec(int n){
        if(n<=1) return 1;
        int sum=0;
        for(int i=1;i<=n;i++){  // think i as a root node
            sum+=solveRec(i-1)*solveRec(n-i);
        }
        return sum;
    }
    int solveMem(int n){
        if(n<=1) return 1;
        if(dp[n]!=-1) return dp[n];
        int sum=0;
        for(int i=1;i<=n;i++){  // think i as a root node
            sum+=solveMem(i-1)*solveMem(n-i);
        }
        return dp[n]=sum;
    }
    int numTrees(int n) {
        //return solveRec(n);
        memset(dp,-1,sizeof(dp));
        return solveMem(n);
    }
};