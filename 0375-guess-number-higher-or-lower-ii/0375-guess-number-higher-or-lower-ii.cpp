class Solution {
public:
    int dp[201][201];
    int solveRec(int start,int end){
        if(start>=end) return 0;
        int ans=INT_MAX;
        for(int i=start;i<=end;i++){
            ans=min(ans,i+max(solveRec(start,i-1),solveRec(i+1,end)));
        }
        return ans;
    }
    int solveMem(int start,int end){
        if(start>=end) return 0;
        if(dp[start][end]!=-1) return dp[start][end];
        int ans=INT_MAX;
        for(int i=start;i<=end;i++){
            ans=min(ans,i+max(solveMem(start,i-1),solveMem(i+1,end)));
        }
        return dp[start][end]=ans;
    }
    int getMoneyAmount(int n) {
       // return solveRec(1,n);
       memset(dp,-1,sizeof(dp));
       return solveMem(1,n);
    }
};