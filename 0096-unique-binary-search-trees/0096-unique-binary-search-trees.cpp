class Solution {
public:
    int dp[22];
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
    int solveTab(int n){
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){ // for no.of node
            for(int j=1;j<=i;j++){ // for root node
              dp[i]+=dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
    int numTrees(int n) {
        //return solveRec(n);
         memset(dp,0,sizeof(dp));
        // return solveMem(n);
        return solveTab(n);
    }
};